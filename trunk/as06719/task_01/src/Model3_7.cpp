#include "Model3_7.h"
#include <cmath>

Model3_7::Model3_7(double coeffA, double coeffB, double timeStep)
    : a(coeffA), b(coeffB), dt(timeStep) {}

double Model3_7::calculateNext(double input) {
    const double y_curr = getY();

    // Явный метод Эйлера для уравнения dy/dt = -exp(a)*y + b*u
    const double derivative = -std::exp(a) * y_curr + b * input;
    const double y_next = y_curr + dt * derivative;

    setY(y_next);

    return y_next;
}

void Model3_7::reset() {
    setY(0.0);
}