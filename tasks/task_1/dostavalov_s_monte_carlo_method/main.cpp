// Copyright 2023 Dostavalov Semen
#include <gtest/gtest.h>
#include <cmath>
#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <iostream>
#include "task_1/dostavalov_s_monte_carlo_method/monte_carlo.h"
#include <mpi.h>

TEST(MPI_TESTS, test1) {
    int ProcRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);

    int a, b, h, N;
    h = 4;
    a = 0;
    b = 8;
    N = 200000;

    double MPI_result = MPIintegration(N, a, b, h, function1);
    if (ProcRank == 0) {
        double not_MPI_result = notMPIintegration(N, a, b, h, function1);
        ASSERT_NEAR(MPI_result, not_MPI_result, 1);
    }
}

TEST(MPI_TESTS, test2) {
    int ProcRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    int a, b, h, N;
    h = 4;
    a = 1;
    b = 4;
    N = 200000;

    double MPI_result = MPIintegration(N, a, b, h, function2);
    if (ProcRank == 0) {
        double not_MPI_result = notMPIintegration(N, a, b, h, function2);
        ASSERT_NEAR(MPI_result, not_MPI_result, 1);
    }
}

TEST(MPI_TESTS, test3) {
    int ProcRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    int a, b, h, N;
    h = 4;
    a = 0;
    b = 10;
    N = 200000;

    double MPI_result = MPIintegration(N, a, b, h, function3);
    if (ProcRank == 0) {
        double not_MPI_result = notMPIintegration(N, a, b, h, function3);
        ASSERT_NEAR(MPI_result, not_MPI_result, 1);
    }
}

TEST(MPI_TESTS, test4) {
    int ProcRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    int a, b, h, N;
    h = 4;
    a = -2;
    b = 11;
    N = 200000;

    double MPI_result = MPIintegration(N, a, b, h, function4);
    if (ProcRank == 0) {
        double not_MPI_result = notMPIintegration(N, a, b, h, function4);
        ASSERT_NEAR(MPI_result, not_MPI_result, 1);
    }
}

TEST(MPI_TESTS, test5) {
    int ProcRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    int a, b, h, N;
    h = 20;
    a = 26;
    b = 30;
    N = 200000;

    double MPI_result = MPIintegration(N, a, b, h, function1);
    if (ProcRank == 0) {
        double not_MPI_result = notMPIintegration(N, a, b, h, function1);
        ASSERT_NEAR(MPI_result, not_MPI_result, 1);
    }
}

TEST(MPI_TESTS, test6) {
    int ProcRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    int a, b, h, N;
    h = 4;
    a = 20;
    b = 10;
    N = 40000;

    ASSERT_ANY_THROW(MPIintegration(N, a, b, h, function3));
}

TEST(MPI_TESTS, test7) {
    int ProcRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    int a, b, h, N;
    h = 4;
    a = 20;
    b = 10;
    N = 0;

    ASSERT_ANY_THROW(MPIintegration(N, a, b, h, function3));
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
