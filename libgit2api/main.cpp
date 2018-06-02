
/** ****************************************************************************
 * 
 * 
 *                          Windows Git API Assitant
 * 
 * 
 *  ****************************************************************************
 * 
 *  @author: Jose Fernando Lopez Fernandez
 *  @date: 02-June-2018
 *  @version: 0.0.1
 *  
 *  @todo: Create program configuration handling system
 *  @todo: Refactor the program options namespace
 * 
 *  ***************************************************************************/

#define TRUE  1
#define FALSE 0

#define DEBUG TRUE
#define DISABLED TRUE

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
    #define Sleep(a) Sleep(a * 1000)
#else
    #include <unistd.h>
#endif

/** C Standard Library Headers:
 *  1. C Standard Lib
 * 
 */

#include <cstdlib>

/** C++ Standard Template Library Headers
 *  1. IO Streams
 *
 */

#include <iostream>

/** Boost Headers
 *  1. Program Options
 *  
 */

// TODO: Implement logger
//#include <boost/log/core.hpp>
#include <boost/program_options.hpp>

// LibGit2 Header
#include <git2.h>

void ShowHelp() noexcept
{
    std::cout << "<Show Help>\n";

    std::exit(EXIT_SUCCESS);
}

void ShowVersion() noexcept
{
    std::cout << "<Show Version>\n";

    std::exit(EXIT_SUCCESS);
}

void SayHi() noexcept
{
    // TODO: Change this exit handler
}

int main(const int argc, char *argv[])
{
    std::atexit(SayHi);

    boost::program_options::options_description genericOptions("Generic options");

    genericOptions.add_options()
        ("help,h", "Show this help message and exit")
        ("version", "Show program version")
    ;

    boost::program_options::variables_map map;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, genericOptions), map);
    boost::program_options::notify(map);

    if (map.count("help")) {
        std::cout << "<Show help>\n";

        return EXIT_SUCCESS;
    }

    if (map.count("version")) {
        std::cout << "<Show Version>\n";

        return EXIT_SUCCESS;
    }

    // Just messing around from here on, not yet trying to really get into the API
    git_libgit2_init();

    std::cout << "Initializing git repository in current directory: \n";
    git_repository *repository = nullptr;

    const auto repoInitializationStatus = git_repository_init(&repository, ".", false);

    git_libgit2_shutdown();
}
