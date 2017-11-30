#ifndef IOBJECT_HPP_INCLUDED
#define IOBJECT_HPP_INCLUDED

class IObject
{
public:
    IObject(){mAlive=true;}
    virtual ~IObject(){}

    virtual void update(){}

    virtual void respawn(){mAlive=true;}
    virtual void kill(){mAlive=false;}

    bool isAlive(){return mAlive;}

protected:
    bool mAlive;
};

#endif // IOBJECT_HPP_INCLUDED
