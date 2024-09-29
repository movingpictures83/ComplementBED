#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "ComplementBEDPlugin.h"

void ComplementBEDPlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
}

void ComplementBEDPlugin::run() {}

void ComplementBEDPlugin::output(std::string file) {
 std::string outputfile = file;
myCommand += "complementBed -i";
myCommand += " ";
addRequiredParameterNoFlag("bedfile");
addRequiredParameter("-g", "genome");
myCommand += " >& "+outputfile + " ";
 system(myCommand.c_str());
}

PluginProxy<ComplementBEDPlugin> ComplementBEDPluginProxy = PluginProxy<ComplementBEDPlugin>("ComplementBED", PluginManager::getInstance());
