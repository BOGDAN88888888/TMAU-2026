#ifndef MODEL_3_7_H
#define MODEL_3_7_H

#include "Model.h"

// Модель в виде дифференциального уравнения (вариант 3.7):
// dy/dt = -exp(a)*y + b*u, интегрируется явным методом Эйлера
// с шагом dt.
class Model3_7 : public Model {
public:
    Model3_7(double coeffA, double coeffB, double timeStep);

    double calculateNext(double input) override;
    void reset() override;

private:
    // Параметры уравнения и шаг интегрирования
    double a;
    double b;
    double dt;
};

#endif // MODEL_3_7_H