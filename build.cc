#include "main.h"

int main(int argc, char** argv){
    std::string sub_dir {argv[1]};
    std::regex e ("\\s+");
    std::string pwd = std::regex_replace(get_current_working_directory(), e, "\\ ");
    printf("%s", pwd.c_str());
    std::string compile_command = "clang++ -std=c++17 -stdlib=libc++ -march=native ";
    compile_command.append(pwd).append("/").append(sub_dir).append(" -o ");
    compile_command.append(pwd).append("/compiled/program");

    std::string delete_build_cm = "rm -rf ";
    delete_build_cm.append(pwd).append("/compiled/program");

    std::string mkdir_build_cm = "mkdir -p ";
    mkdir_build_cm.append(pwd).append("/compiled");

    std::string run_command = "";
    run_command.append(pwd).append("/compiled/program");

    system(mkdir_build_cm.c_str());
    system(delete_build_cm.c_str());
    system(compile_command.c_str());
    printf("\n\nDo you want to run the compiled file? (Y/n)\n");
    std::string ans;
    std::getline(std::cin, ans);
    if(to_lower(ans) == "y")
        system(run_command.c_str());
    return 0;
}