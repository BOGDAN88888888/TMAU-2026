#ifndef MODEL_1_9_H
#define MODEL_1_9_H

#include "Model.h"

// Линейная дискретная модель 2-го порядка (вариант 1.9):
// y[k] = a1*y[k-1] + a2*y[k-2] + a3*y[k-3] + b1*u[k]
class Model1_9 : public Model {
public:
    Model1_9(double coeffA1, double coeffA2, double coeffA3, double coeffB1);

    double calculateNext(double input) override;
    void reset() override;

private:
    // Коэффициенты рекуррентного соотношения
    double a1;
    double a2;
    double a3;
    double b1;

    // История двух предыдущих выходов
    double y_prev1 = 0.0;
    double y_prev2 = 0.0;
};

#endif // MODEL_1_9_H