<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “теория и методы автоматического управления”</p>
<p align="center">Тема: “Моделирование контролируемых объектов”</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-67</p>
<p align="right">Кошелев Б.В.</p>
<p align="right">Проверил:</p>
<p align="right">Дворанинович Д. А.</p>
<br><br><br><br><br>
<p align="center">Брест 2026</p>
 
 
 
 
## Вариант 19
 
## Математические уравнения моделей (Вариант 19)
1. **Линейная модель (Model 1.9):**
   $$Y_{\tau+1} = a_1 Y_{\tau} + a_2 Y_{\tau-1} + a_3 Y_{\tau-2} + b_1 u_{\tau}$$
2. **Нелинейная модель (Model 2.3):**
   $$Y_{\tau+1} = a_1 Y_{\tau} - b_1 Y_{\tau-1}^2 + c_1 u_{\tau}$$
3. **Дифференциальное уравнение (Model 3.7):**
   $$\frac{dy}{dt} = -e^a y + b u$$
   Численное решение методом Эйлера: $y_{t+1} = y_t + \Delta t \cdot (-e^a y_t + b u_t)$

 
## Архитектура классов (UML-диаграмма)
Ниже представлена интерактивная UML-диаграмма классов разработанного программного комплекса:

```mermaid
classDiagram
    direction LR

    class Model {
        <<abstract>>
        #y_curr : double
        +getY() double
        +setY(value : double) void
        +calculateNext(input : double) double
        +reset() void
    }

    class Model3_7 {
        -a : double
        -b : double
        -dt : double
        +Model3_7(coeffA : double, coeffB : double, timeStep : double)
        +calculateNext(input : double) double
        +reset() void
    }

    class Model2_3 {
        -a1 : double
        -b1 : double
        -c1 : double
        -y_prev1 : double
        +Model2_3(coeffA1 : double, coeffB1 : double, coeffC1 : double)
        +calculateNext(input : double) double
        +reset() void
    }

    class Model1_9 {
        -a1 : double
        -a2 : double
        -a3 : double
        -b1 : double
        -y_prev1 : double
        -y_prev2 : double
        +Model1_9(coeffA1 : double, coeffA2 : double, coeffA3 : double, coeffB1 : double)
        +calculateNext(input : double) double
        +reset() void
    }

    Model <|-- Model1_9 : наследует
    Model <|-- Model2_3 : наследует
    Model <|-- Model3_7 : наследует
```

## Результаты моделирования и визуализация
Программа успешно выполняет симуляцию всех трех моделей для трех типов входных воздействий (ступенчатое, импульсное, гармоническое) и экспортирует результаты в `.csv` файлы.

### Графики переходных процессов (Python/Matplotlib)
На основе сгенерированных табличных данных с помощью библиотеки Matplotlib построены графики процессов симуляции контролируемых объектов:

![Результаты моделирования](simulation_results.png)

