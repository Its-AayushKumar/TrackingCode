enum PlanetType { terrestrial, gas, ice }

PlanetType myPlanet = PlanetType.terrestrial;

void describe(PlanetType type) {
  switch (type) {
    case PlanetType.terrestrial:
      print("Rocky world");
    case PlanetType.gas:
      print("Gas giant");
    case PlanetType.ice:
      print("Ice giant");
  }
}

void main() {
  // describe(PlanetType.gas);
  describe(.gas);
}
