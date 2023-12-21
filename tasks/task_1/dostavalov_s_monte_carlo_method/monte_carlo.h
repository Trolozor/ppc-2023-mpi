// Copyright 2023 Dostavalov Semen
#ifndef TASKS_TASK_1_DOSTAVALOV_S_MONTE_CARLO_METHOD_MONTE_CARLO_H_
#define TASKS_TASK_1_DOSTAVALOV_S_MONTE_CARLO_METHOD_MONTE_CARLO_H_

#include <mpi.h>
#include <random>
#include <functional>
double function1(double x);
double function2(double x);
double function3(double x);
double function4(double x);

double notMPIintegration(int N, int a, int b, int h, double (*func)(double));
double MPIintegration(int N, int a, int b, int h, double (*func)(double));

#endif  // TASKS_TASK_1_DOSTAVALOV_S_MONTE_CARLO_METHOD_MONTE_CARLO_H_
