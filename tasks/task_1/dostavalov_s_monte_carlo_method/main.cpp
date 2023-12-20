// Copyright 2023 Dostavalov Semen
#include <gtest/gtest.h>
#include <cmath>
#include <mpi.h>
#include "task_1/dostavalov_s_monte_carlo_method/monte_carlo.h"

double f1(double x) { return (pow(x, 2)); }
double f2(double x) { return (1 / log(x)); }
double f3(double x) { return (exp(x) / x); }
double f4(double x) { return (log(x) + (5 * x)); }
double f5(double x) { return (exp(x) * pow(x, 2)); }


TEST(MPI_TESTS, Test_xx) {
    double err = 0.1;
    bool flag = false;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int count = 1000000;
    int low = 0, high = 1;
    double res = floor(monteCarlo(low, high, count, &f1) * 100) / 100;
    double corRes = 0.33;
    if (rank == 0) {
        if (abs(res - corRes) <= err)
            flag = true;
        ASSERT_EQ(flag, true);
    }
}

TEST(MPI_TESTS, Test_hard_log) {
    double err = 0.1;
    bool flag = false;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int count = 1000000;
    int low = 2, high = 3;
    double res = floor(monteCarlo(low, high, count, &f2) * 10) / 10;
    double corRes = 1.1;
    if (rank == 0) {
        if (abs(res - corRes) <= err)
            flag = true;
        ASSERT_EQ(flag, true);
    }
}

TEST(MPI_TESTS, Test_hard_exp) {
    double err = 0.1;
    bool flag = false;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int count = 1000000;
    int low = 1, high = 2;
    double res = floor(monteCarlo(low, high, count, &f3) * 100) / 100;
    double corRes = 3.05;
    if (rank == 0) {
        if (abs(res - corRes) <= err)
            flag = true;
        ASSERT_EQ(flag, true);
    }
}
TEST(MPI_TESTS, Test_log) {
    double err = 0.1;
    bool flag = false;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int count = 1000000;
    int low = 0, high = 1;
    double res = floor(monteCarlo(low, high, count, &f4) * 10) / 10;
    double corRes = 1.9;
    if (rank == 0) {
        if (abs(res - corRes) <= err)
            flag = true;
        ASSERT_EQ(flag, true);
    }
}

TEST(MPI_TESTS, Test_exp) {
    double err = 0.1;
    bool flag = false;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int count = 10000000;
    int low = 0, high = 1;
    double res = floor(monteCarlo(low, high, count, &f5) * 100) / 100;
    double corRes = 0.71;
    if (rank == 0) {
        if (abs(res - corRes) <= err)
            flag = true;
        ASSERT_EQ(flag, true);
    }
}

int main(int argc, char** argv) {
    int res = 0;
    MPI_Init(&argc, &argv);
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();
    res = RUN_ALL_TESTS();
    MPI_Finalize();
    return res;
}