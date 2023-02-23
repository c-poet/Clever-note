add_executable(logger_factory_test logger_factory.cpp)
target_link_libraries(logger_factory_test PRIVATE logger)
add_test(NAME logger_factory_test COMMAND logger_factory_test)

add_executable(log_test log.cpp)
target_link_libraries(log_test PRIVATE logger)
add_test(NAME log_test COMMAND log_test)

