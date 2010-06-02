/*
 *	server/zone/objects/area/ActiveArea.h generated by engine3 IDL compiler 0.60
 */

#ifndef ACTIVEAREA_H_
#define ACTIVEAREA_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#include "engine/util/QuadTreeEntry.h"

#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace objects {
namespace area {

class ActiveArea : public SceneObject {
public:
	ActiveArea();

	void notifyEnter(PlayerCreature* object);

	void notifyExit(PlayerCreature* object);

	bool containsPoint(float x, float y);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	float getRadius();

	void setRadius(float r);

protected:
	ActiveArea(DummyConstructorParameter* param);

	virtual ~ActiveArea();

	friend class ActiveAreaHelper;
};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

namespace server {
namespace zone {
namespace objects {
namespace area {

class ActiveAreaImplementation : public SceneObjectImplementation {
protected:
	float radius;

	float radius2;

public:
	ActiveAreaImplementation();

	ActiveAreaImplementation(DummyConstructorParameter* param);

	virtual void notifyEnter(PlayerCreature* object);

	virtual void notifyExit(PlayerCreature* object);

	bool containsPoint(float x, float y);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	float getRadius();

	void setRadius(float r);

	ActiveArea* _this;

	operator const ActiveArea*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~ActiveAreaImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class ActiveArea;
};

class ActiveAreaAdapter : public SceneObjectAdapter {
public:
	ActiveAreaAdapter(ActiveAreaImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void notifyEnter(PlayerCreature* object);

	void notifyExit(PlayerCreature* object);

	bool containsPoint(float x, float y);

	float getRadius();

	void setRadius(float r);

};

class ActiveAreaHelper : public DistributedObjectClassHelper, public Singleton<ActiveAreaHelper> {
	static ActiveAreaHelper* staticInitializer;

public:
	ActiveAreaHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ActiveAreaHelper>;
};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

#endif /*ACTIVEAREA_H_*/
