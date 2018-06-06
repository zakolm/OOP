#pragma once

#include <string>
#include "absLoader.h"
#include "sceneFacade.h"
#include "drawerVs.h"
#include "modelBuilder.h"

class cCommand
{
public:
    virtual void execute(cSceneFacade& facade) = 0;
    virtual ~cCommand() { };

protected:
    cCommand() { };
    cCommand(objIterator _start)
        : start(_start)
    {
        end = start + 1;
    }
    cCommand(objIterator _start, objIterator _end)
        : start(_start), end(_end) { }
    
    objIterator start;
    objIterator end;
};

class cLoadCommand: public cCommand
{
public:
    cLoadCommand(cAbsLoader& _loader, cBaseModelBuilder& _builder) :
        loader(_loader), builder(_builder) { }
    ~cLoadCommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        cModel* model = facade.getLoadManager().loadModel(loader, builder);
        facade.addModel(model);
    }

private:
    cAbsLoader& loader;
    cBaseModelBuilder& builder;
};

class cSaveCommand : public cCommand
{
public:
    cSaveCommand(objIterator iter, cAbsLoader& _saver) 
        : cCommand(iter), saver(_saver) { }
    cSaveCommand(objIterator start, objIterator end, cAbsLoader& _saver)
        : cCommand(start, end), saver(_saver) { }
    ~cSaveCommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        facade.getLoadManager().saveModel(saver, start, end);
    }

private:
    cAbsLoader& saver;
};

class cRemModelCommand : public cCommand
{
public:
    cRemModelCommand(objIterator iter) : cCommand(iter) { }
    cRemModelCommand(objIterator start, objIterator end)
        : cCommand(start, end) { }
    ~cRemModelCommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        facade.remModel(start, end);
    }
};

class cShiftCommand : public cCommand
{
public:
    cShiftCommand(double _dx, double _dy, double _dz, objIterator iter)
        : cCommand(iter), dx(_dx), dy(_dy), dz(_dz) { }
    cShiftCommand(double _dx, double _dy, double _dz, objIterator start, objIterator end)
        : cCommand(start, end), dx(_dx), dy(_dy), dz(_dz) { }
    ~cShiftCommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        facade.getTransformManager().shiftModel(dx, dy, dz, start, end);
    }

private:
    double dx, dy, dz;
};

class cScaleCommand : public cCommand
{
public:
    cScaleCommand(const double _kx, const double _ky, const double _kz, objIterator iter)
        : cCommand(iter), kx(_kx), ky(_ky), kz(_kz) { }
    cScaleCommand(const double _kx, const double _ky, const double _kz, objIterator start, objIterator end)
        : cCommand(start, end), kx(_kx), ky(_ky), kz(_kz) { }
    ~cScaleCommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        facade.getTransformManager().scaleModel(kx, ky, kz, start, end);
    }

private:
    const double kx, ky, kz;
};

class cRotateXcommand : public cCommand
{
public:
    cRotateXcommand(double _angle, objIterator iter)
        : cCommand(iter), angle(_angle) { }
    cRotateXcommand(double _angle, objIterator start, objIterator end)
        : cCommand(start, end), angle(_angle) { }
    ~cRotateXcommand() { }

    virtual void execute(cSceneFacade &facade) override
    {
        facade.getTransformManager().rotateXModel(angle, start, end);
    }

private:
    double angle;
};

class cRotateYcommand : public cCommand
{
public:
    cRotateYcommand(double _angle, objIterator iter)
        : cCommand(iter), angle(_angle) { }
    cRotateYcommand(double _angle, objIterator start, objIterator end)
        : cCommand(start, end), angle(_angle) { }
    ~cRotateYcommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        facade.getTransformManager().rotateYModel(angle, start, end);
    }

private:
    double angle;
};

class cRotateZcommand : public cCommand
{
public:
    cRotateZcommand(double _angle, objIterator iter)
        : cCommand(iter), angle(_angle) { }
    cRotateZcommand(double _angle, objIterator start, objIterator end)
        : cCommand(start, end), angle(_angle) { }
    ~cRotateZcommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        facade.getTransformManager().rotateZModel(angle, start, end);
    }

private:
    double angle;
};

class cDrawCommand : public cCommand
{
public:
    cDrawCommand(cBaseDrawer& _drawer)
        : drawer(_drawer){ }
    ~cDrawCommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        cCamera* cam = facade.getCurCamera();
        drawer.setCamera(cam);
        facade.getDrawManager().draw(drawer, facade.getSceneContainer().posBegin(), facade.getSceneContainer().objBegin(), facade.getSceneContainer().objEnd());
    }

private:
    cBaseDrawer& drawer;
};

class cAddCameraCommand : public cCommand
{
public:
    cAddCameraCommand(cCamera* _camera)
        : camera(_camera) { }
    ~cAddCameraCommand() { }

    virtual void execute(cSceneFacade& facade) override
    {
        facade.addCamera(camera);
    }

private:
    cCamera *camera;
};
