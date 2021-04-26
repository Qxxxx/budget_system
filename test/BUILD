load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "budget_calculator_unit_tests",
    size = "small",
    srcs = ["budget_calculator_unit_tests.cpp"],
    deps = [
        "//budget_calculator",
        "@com_google_googletest//:gtest_main",
    ],
)
