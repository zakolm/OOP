#pragma once

#include <fstream>
#include "impLoader.h"
#include "modelBuilder.h"
#include "fileLoaderExceptions.h"

class cFileLoader: public cImpLoader
{
public:
    explicit cFileLoader(std::string _fileName)
        : fileName(_fileName) { }
    virtual ~cFileLoader() override;
    virtual cModel* loadModel(cBaseModelBuilder& builder) override;
    virtual void saveModel(cModel model) override;

    void openLoad();
    void openSave();
    void close();

private:
    std::string fileName;
    std::ifstream input;
    std::ofstream output;
};
