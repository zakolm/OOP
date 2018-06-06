#include "fileLoader.h"

cFileLoader::~cFileLoader()
{
    close();
}

cModel* cFileLoader::loadModel(cBaseModelBuilder& builder)
{
    openLoad();

    if (!input.is_open())
        throw cFileInputStrNotOpen();

    char* buffer = new char[50];
    int count;

    input >> buffer;

    builder.buildModel(buffer);

    input >> count;

    for (int i = 0; i < count; i++)
    {
        double x, y, z;
        input >> buffer >> x >> y >> z;
        builder.buildPoint(buffer, x, y, z);
    }

    input >> count;

    for (int i = 0; i < count; i++)
    {
        int start, end;
        input >> start >> end;
        builder.buildEdge(start, end);
    }

    delete [] buffer;
    
    close();

    return builder.getModel();
}

void cFileLoader::saveModel(cModel model)
{
    openSave();

    if (!output.is_open())
        throw cFileOutputStrNotOpen();

    output << model.getName() << std::endl;
    output << model.getCountPoints() << std::endl;

    for (int i = 0; i < model.getCountPoints(); i++)
        output << "point" << i << " " << model.getPoints()[i].getX() << \
            " " << model.getPoints()[i].getY() << " " << model.getPoints()[i].getZ() << std::endl;

    output << model.getCountEdges() << std::endl;

    for (int i = 0; i < model.getCountEdges(); i++)
        output << model.getEdges()[i].getStart() << " " << model.getEdges()[i].getEnd() << std::endl;

    close();
}

void cFileLoader::openLoad()
{
    input.open(fileName);
}

void cFileLoader::openSave()
{
    output.open(fileName);
}

void cFileLoader::close()
{
    if (input.is_open())
        input.close();

    if (output.is_open())
        output.close();
}
