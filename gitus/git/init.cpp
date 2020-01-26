#include "init.h"

#include <iostream>
#include <fstream>

bool checkInit() {
    // Recuperer le chemin actuel
    auto path = boost::filesystem::current_path();

    // Verfier si le dossier '.git' existe
    if(boost::filesystem::exists(".git") && boost::filesystem::exists(".git/index") && boost::filesystem::exists(".git/objects")) {
        return true;

    }else {
        return false;

    }
}

bool getInitHelp() {
    // Affichage du "./gitus init --help"

    try {
        std::cout << "usage: gitus init" << std::endl;

        return true;

    }catch(std::string const& chaine) {
        std::cerr << chaine << std::endl;

        return false;
    
    }
}

bool setInit() throw(boost::filesystem::filesystem_error) {
    try {
        // Recuperer le chemin actuel
        auto path = boost::filesystem::current_path();

        // Creer le dossier '.gitus'
        const auto pathFolderGitus = path.append(".git");
        boost::filesystem::create_directory(pathFolderGitus);

        // Creer le fichier 'index'
        boost::filesystem::ofstream index(".git/index");
        index.close();

        // Creer le dossier 'objects'
        const auto pathFolderObjects = path.append("objects");
        boost::filesystem::create_directory(pathFolderObjects);

        return true;
        
    }catch(std::string const& chaine) {
        std::cerr << chaine << std::endl;

        return false;
    
    }
}
