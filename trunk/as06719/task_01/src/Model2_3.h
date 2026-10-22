#ifndef MODEL_2_3_H
#define MODEL_2_3_H

#include "Model.h"

// Нелинейная дискретная модель (вариант 2.3):
// y[k] = a1*y[k-1] - b1*(y[k-2])^2 + c1*u[k]
class Model2_3 : public Model {
public:
    Model2_3(double coeffA1, double coeffB1, double coeffC1);

    double calculateNext(double input) override;
    void reset() override;

private:
    // Коэффициенты нелинейного соотношения
    double a1;
    double b1;
    double c1;

    // Предыдущее значение выхода
    double y_prev1 = 0.0;
};

#endif // MODEL_2_3_H