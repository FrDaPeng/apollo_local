load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])
PREDICTION_COPTS = ["-DMODULE_NAME=\\\"prediction\\\""]
PREDICTION_FOPENMP_COPTS = ["-DMODULE_NAME=\\\"prediction\\\"","-fopenmp"]

cc_library(
    name = "mlp_evaluator",
    srcs = ["mlp_evaluator.cc"],
    hdrs = ["mlp_evaluator.h"],
    copts = PREDICTION_COPTS,
    deps = [
        "//modules/prediction/common:feature_output",
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/common:validation_checker",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//modules/prediction/proto:fnn_vehicle_model_cc_proto",
    ],
)

cc_test(
    name = "mlp_evaluator_test",
    size = "small",
    srcs = ["mlp_evaluator_test.cc"],
    data = [
        "//modules/prediction:prediction_data",
        "//modules/prediction:prediction_testdata",
    ],
    deps = [
        "//modules/prediction/common:kml_map_based_test",
        "//modules/prediction/evaluator/vehicle:mlp_evaluator",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "cost_evaluator",
    srcs = ["cost_evaluator.cc"],
    hdrs = ["cost_evaluator.h"],
    copts = PREDICTION_COPTS,
    deps = [
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
    ],
)

cc_test(
    name = "cost_evaluator_test",
    size = "small",
    srcs = ["cost_evaluator_test.cc"],
    data = [
        "//modules/prediction:prediction_data",
        "//modules/prediction:prediction_testdata",
    ],
    deps = [
        "//modules/prediction/common:kml_map_based_test",
        "//modules/prediction/evaluator/vehicle:cost_evaluator",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "junction_mlp_evaluator",
    srcs = ["junction_mlp_evaluator.cc"],
    hdrs = ["junction_mlp_evaluator.h"],
    copts = PREDICTION_FOPENMP_COPTS,
    deps = [
        "//modules/common/math",
        "//modules/prediction/common:feature_output",
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/container:container_manager",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//third_party:libtorch",
    ],
)

cc_test(
    name = "junction_mlp_evaluator_test",
    size = "small",
    srcs = ["junction_mlp_evaluator_test.cc"],
    data = [
        "//modules/prediction:prediction_data",
        "//modules/prediction:prediction_testdata",
    ],
    linkopts = [
        "-lgomp",
    ],
    deps = [
        "//modules/prediction/common:kml_map_based_test",
        "//modules/prediction/evaluator/vehicle:junction_mlp_evaluator",
        "@com_google_googletest//:gtest_main",
    ],
    linkstatic = True,
)

cc_library(
    name = "junction_map_evaluator",
    srcs = ["junction_map_evaluator.cc"],
    hdrs = ["junction_map_evaluator.h"],
    copts = PREDICTION_FOPENMP_COPTS,
    deps = [
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/common:semantic_map",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//third_party:libtorch",
    ],
)

cc_library(
    name = "cruise_mlp_evaluator",
    srcs = ["cruise_mlp_evaluator.cc"],
    hdrs = ["cruise_mlp_evaluator.h"],
    copts = PREDICTION_FOPENMP_COPTS,
    deps = [
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/container:container_manager",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//third_party:libtorch",
    ],
)

cc_test(
    name = "cruise_mlp_evaluator_test",
    size = "small",
    srcs = ["cruise_mlp_evaluator_test.cc"],
    data = [
        "//modules/prediction:prediction_data",
        "//modules/prediction:prediction_testdata",
    ],
    linkopts = [
        "-lgomp",
    ],
    deps = [
        "//modules/prediction/common:kml_map_based_test",
        "//modules/prediction/evaluator/vehicle:cruise_mlp_evaluator",
    ],
    linkstatic = True,
)

cc_library(
    name = "lane_scanning_evaluator",
    srcs = ["lane_scanning_evaluator.cc"],
    hdrs = ["lane_scanning_evaluator.h"],
    copts = PREDICTION_FOPENMP_COPTS,
    deps = [
        "//modules/prediction/container:container_manager",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//third_party:libtorch",
    ],
)

cc_library(
    name = "lane_aggregating_evaluator",
    srcs = ["lane_aggregating_evaluator.cc"],
    hdrs = ["lane_aggregating_evaluator.h"],
    copts = PREDICTION_COPTS,
    deps = [
        "//modules/prediction/container:container_manager",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//third_party:libtorch",
    ],
)

cc_library(
    name = "semantic_lstm_evaluator",
    srcs = ["semantic_lstm_evaluator.cc"],
    hdrs = ["semantic_lstm_evaluator.h"],
    copts = PREDICTION_FOPENMP_COPTS,
    deps = [
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/common:semantic_map",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//third_party:libtorch",
        "@eigen",
    ],
)

cc_library(
    name = "jointly_prediction_planning_evaluator",
    srcs = ["jointly_prediction_planning_evaluator.cc"],
    hdrs = ["jointly_prediction_planning_evaluator.h"],
    copts = PREDICTION_FOPENMP_COPTS,
    deps = [
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/common:semantic_map",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//modules/prediction/pipeline:vector_net",
        "//third_party:libtorch",
        "@eigen",
    ],
)

cc_library(
    name = "vectornet_evaluator",
    srcs = ["vectornet_evaluator.cc"],
    hdrs = ["vectornet_evaluator.h"],
    copts = PREDICTION_FOPENMP_COPTS,
    deps = [
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/evaluator",
        "//modules/prediction/pipeline:vector_net",
        "//third_party:libtorch",
        "@eigen",
    ],
)

cpplint()
