namespace FastFourierTransform {
  using real = double;

  struct Complex {
    real realPart, imaginaryPart;

    Complex() : realPart(0), imaginaryPart(0) {}

    Complex(real realPart, real imaginaryPart) : realPart(realPart), imaginaryPart(imaginaryPart) {}

    inline Complex operator+(const Complex &c) const { return Complex(realPart + c.realPart, imaginaryPart + c.imaginaryPart); }

    inline Complex operator-(const Complex &c) const { return Complex(realPart - c.realPart, imaginaryPart - c.imaginaryPart); }

    inline Complex operator*(const Complex &c) const { return Complex(realPart * c.realPart - imaginaryPart * c.imaginaryPart, realPart * c.imaginaryPart + imaginaryPart * c.realPart); }

    inline Complex conj() const { return Complex(realPart, -imaginaryPart); }
  };

  const real PI = acos(-1);
  int currentBase = 1;
  std::vector<Complex> roots = { {0, 0}, {1, 0} };
  std::vector<int> reverseIndices = {0, 1};

  void ensureBase(int requiredBase) {
    if (requiredBase <= currentBase) return;
    reverseIndices.resize(1 << requiredBase);
    roots.resize(1 << requiredBase);

    for (int i = 0; i < (1 << requiredBase); i++) {
      reverseIndices[i] = (reverseIndices[i >> 1] >> 1) + ((i & 1) << (requiredBase - 1));
    }

    while (currentBase < requiredBase) {
      real angle = PI * 2.0 / (1 << (currentBase + 1));
      for (int i = 1 << (currentBase - 1); i < (1 << currentBase); i++) {
        roots[i << 1] = roots[i];
        real angle_i = angle * (2 * i + 1 - (1 << currentBase));
        roots[(i << 1) + 1] = Complex(cos(angle_i), sin(angle_i));
      }
      ++currentBase;
    }
  }

  void fft(std::vector<Complex> &array, int n) {
    assert((n & (n - 1)) == 0);
    int trailingZeros = __builtin_ctz(n);
    ensureBase(trailingZeros);
    int shift = currentBase - trailingZeros;

    for (int i = 0; i < n; i++) {
      if (i < (reverseIndices[i] >> shift)) {
        std::swap(array[i], array[reverseIndices[i] >> shift]);
      }
    }

    for (int size = 1; size < n; size <<= 1) {
      for (int i = 0; i < n; i += 2 * size) {
        for (int j = 0; j < size; j++) {
          Complex z = array[i + j + size] * roots[j + size];
          array[i + j + size] = array[i + j] - z;
          array[i + j] = array[i + j] + z;
        }
      }
    }
  }

  std::vector<int64_t> multiply(const std::vector<int> &a, const std::vector<int> &b) {
    int resultSize = (int)a.size() + (int)b.size() - 1;
    int requiredBase = 1;
    while ((1 << requiredBase) < resultSize) requiredBase++;
    ensureBase(requiredBase);

    int fftSize = 1 << requiredBase;
    std::vector<Complex> fftArray(fftSize);

    for (int i = 0; i < fftSize; i++) {
      int x = (i < (int)a.size() ? a[i] : 0);
      int y = (i < (int)b.size() ? b[i] : 0);
      fftArray[i] = Complex(x, y);
    }

    fft(fftArray, fftSize);

    Complex rotationFactor(0, -0.25 / (fftSize >> 1)), scalingFactor(0, 1), halfFactor(0.5, 0);

    for (int i = 0; i <= (fftSize >> 1); i++) {
      int j = (fftSize - i) & (fftSize - 1);
      Complex z = (fftArray[j] * fftArray[j] - (fftArray[i] * fftArray[i]).conj()) * rotationFactor;
      fftArray[j] = (fftArray[i] * fftArray[i] - (fftArray[j] * fftArray[j]).conj()) * rotationFactor;
      fftArray[i] = z;
    }

    for (int i = 0; i < (fftSize >> 1); i++) {
      Complex A0 = (fftArray[i] + fftArray[i + (fftSize >> 1)]) * halfFactor;
      Complex A1 = (fftArray[i] - fftArray[i + (fftSize >> 1)]) * halfFactor * roots[(fftSize >> 1) + i];
      fftArray[i] = A0 + A1 * scalingFactor;
    }

    fft(fftArray, fftSize >> 1);

    std::vector<int64_t> result(resultSize);
    for (int i = 0; i < resultSize; i++) {
      result[i] = llround(i & 1 ? fftArray[i >> 1].imaginaryPart : fftArray[i >> 1].realPart);
    }
    return result;
  }
};
