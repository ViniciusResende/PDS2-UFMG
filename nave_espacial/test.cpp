int lowerIndex = -1;
  float lowerDistance = -1;

  auto setupValues = [&lowerIndex, &lowerDistance](int idx, float value) {
    lowerIndex = idx;
    lowerDistance = value;
  };

  for (int i = 0; i < n; i++) {
    int distance = this->calcular_distancia(naves[i]);

    if(lowerDistance != -1) {
      if(distance < lowerDistance) {
        setupValues(i, distance);
      }
    } else {
      setupValues(i, distance);
    }
  }

  return naves[lowerIndex];