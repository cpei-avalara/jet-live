
#pragma once

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include "jet/live/ICompilationUnitsParser.hpp"
#include "jet/live/IDependenciesHandler.hpp"
#include "jet/live/IProgramInfoLoader.hpp"
#include "jet/live/LiveDelegate.hpp"

namespace jet
{
    /**
     * A bunch of data which is shared between different classes.
     */
    struct LiveContext
    {
        /** Current delegate. */
        std::unique_ptr<LiveDelegate> delegate;

        /** Current compilation units parser. */
        std::unique_ptr<ICompilationUnitsParser> compilationUnitsParser;

        /** Current dependencies handler. */
        std::unique_ptr<IDependenciesHandler> dependenciesHandler;

        /** Current program info loader. */
        std::unique_ptr<IProgramInfoLoader> programInfoLoader;

        /**
         * All programs which are living in the address space if this process (executables
         * and shared libraries) in order of loading.
         */
        std::vector<Program> programs;

        /** This executable file path. */
        std::string thisExecutablePath;

        /** Directories which are monitored for changes. */
        std::vector<std::string> dirsToMonitor;

        /** sourceFilePath -> CompilationUnit map. */
        std::unordered_map<std::string, CompilationUnit> compilationUnits;

        /** sourceFilePath -> set of dependency file paths. */
        std::unordered_map<std::string, std::unordered_set<std::string>> dependencies;

        /** dependency file path -> set of sourceFilePaths. */
        std::unordered_map<std::string, std::unordered_set<std::string>> inverseDependencies;
    };
}
