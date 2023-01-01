#include <gflags/gflags.h>
#include "module/func.h"


DEFINE_bool(bool_flag, true, "test gflags");
DEFINE_uint32(int_flag, 1234, "int gflags");
DECLARE_string(string_flags);


int main(int argc, char **argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    std::cout<<FLAGS_bool_flag<<" "<<FLAGS_string_flags<<std::endl;

    FLAGS_string_flags = "new string";

    std::cout<<FLAGS_int_flag<<" "<<FLAGS_string_flags<<std::endl;

    return 0;
}