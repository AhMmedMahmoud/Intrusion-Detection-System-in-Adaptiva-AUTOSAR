#include "../Manifest/manager/manifest_manager.h"

using namespace ara::idsm::manifest;

int main()
{
    std::string path = "../Manifest/manifestBB.json";
    ManifestManager manager(path);

    manager.parseJSON();

    manager.printEventContextMappingsMetaData();

    return 0;
}