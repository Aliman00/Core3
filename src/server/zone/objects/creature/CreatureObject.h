/*
 *	server/zone/objects/creature/CreatureObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef CREATUREOBJECT_H_
#define CREATUREOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class StfParameter;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/lua/LuaObject.h"

#include "system/util/Vector.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject : public TangibleObject {
public:
	CreatureObject(LuaObject* templateData);

	void clearQueueAction(unsigned int actioncntr, float timer = 0, unsigned int tab1 = 0, unsigned int tab2 = 0);

	void sendBaselinesTo(SceneObject* player);

	void sendSystemMessage(const String& message);

	void sendSystemMessage(UnicodeString& message);

	void sendSystemMessage(const String& file, const String& str, unsigned long long targetid = 0);

	void sendSlottedObjectsTo(SceneObject* player);

	void sendSystemMessage(const String& file, const String& str, StfParameter* param);

	int getBankCredits();

	int getCashCredits();

	int getBaseHealth(int idx);

	unsigned int getBaseHealthUpdateCounter();

	int getWounds(int idx);

	unsigned int getWoundsUpdateCounter();

	unsigned int getEncumbrancesUpdateCounter();

	unsigned int getHamListUpdateCounter();

	int getHAM(int idx);

	unsigned int getMaxHamListUpdateCounter();

	int getMaxHAM(int idx);

	int getEncumbrance(int idx);

	byte getPosture();

	byte getFactionRank();

	unsigned long long getCreatureLinkID();

	float getShockWounds();

	unsigned long long getStateBitmask();

	unsigned long long getListenID();

	float getRunSpeed();

	float getWalkSpeed();

	float getTerrainNegotiation();

	float getRunAcceleration();

	float getWalkAcceleration();

	int getLevel();

	String getPerformanceAnimation();

	String getMoodString();

	unsigned long long getWeaponID();

	unsigned long long getGroupID();

	unsigned long long getGroupInviterID();

	unsigned long long getGroupInviteCounter();

	int getGuildID();

	unsigned long long getTargetID();

	byte getMoodID();

	float getSlopeModPercent();

	int getPerformanceCounter();

	int getInstrumentID();

	byte getFrozen();

	float getHeight();

	int getSpecies();

	void setHeight(float heigh);

	void setWeaponID(unsigned long long objectID, bool notifyClient = false);

	void setTargetID(unsigned long long targetID, bool notifyClient = false);

protected:
	CreatureObject(DummyConstructorParameter* param);

	virtual ~CreatureObject();

	String _return_getMoodString;
	String _return_getPerformanceAnimation;

	friend class CreatureObjectHelper;
};

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObjectImplementation : public TangibleObjectImplementation {
protected:
	int bankCredits;

	int cashCredits;

	int gender;

	int species;

	Vector<int> baseHealth;

	unsigned int baseHealthUpdateCounter;

	byte posture;

	byte factionRank;

	unsigned long long creatureLinkID;

	float shockWounds;

	Vector<int> wounds;

	unsigned int woundsUpdateCounter;

	unsigned long long stateBitmask;

	Vector<int> encumbrances;

	unsigned int encumbrancesUpdateCounter;

	float runSpeed;

	float walkSpeed;

	float terrainNegotiation;

	float runAcceleration;

	float walkAcceleration;

	float height;

	float slopeModPercent;

	float slopeModAngle;

	unsigned long long listenToID;

	short level;

	String performanceAnimation;

	String moodString;

	unsigned long long weaponID;

	unsigned long long groupID;

	unsigned long long groupInviterID;

	unsigned long long groupInviteCounter;

	int guildID;

	unsigned long long targetID;

	byte moodID;

	int performanceCounter;

	int instrumentID;

	Vector<int> hamList;

	unsigned int hamListUpdateCounter;

	Vector<int> maxHamList;

	unsigned int maxHamListUpdateCounter;

	byte frozen;

	String templateString;

public:
	static const int HUMAN = 0;

	static const int RODIAN = 1;

	static const int TRANDOSHAN = 2;

	static const int MONCAL = 3;

	static const int WOOKIE = 4;

	static const int BOTHAN = 5;

	static const int TWILEK = 6;

	static const int ZABRAK = 7;

	static const int ITHORIAN = 0x21;

	static const int SULLUSTAN = 0x31;

	static const int MALE = 0;

	static const int FEMALE = 1;

	CreatureObjectImplementation(LuaObject* templateData);

	void clearQueueAction(unsigned int actioncntr, float timer = 0, unsigned int tab1 = 0, unsigned int tab2 = 0);

	void sendBaselinesTo(SceneObject* player);

	void sendSystemMessage(const String& message);

	void sendSystemMessage(UnicodeString& message);

	void sendSystemMessage(const String& file, const String& str, unsigned long long targetid = 0);

	void sendSlottedObjectsTo(SceneObject* player);

	void sendSystemMessage(const String& file, const String& str, StfParameter* param);

	int getBankCredits();

	int getCashCredits();

	int getBaseHealth(int idx);

	unsigned int getBaseHealthUpdateCounter();

	int getWounds(int idx);

	unsigned int getWoundsUpdateCounter();

	unsigned int getEncumbrancesUpdateCounter();

	unsigned int getHamListUpdateCounter();

	int getHAM(int idx);

	unsigned int getMaxHamListUpdateCounter();

	int getMaxHAM(int idx);

	int getEncumbrance(int idx);

	byte getPosture();

	byte getFactionRank();

	unsigned long long getCreatureLinkID();

	float getShockWounds();

	unsigned long long getStateBitmask();

	unsigned long long getListenID();

	float getRunSpeed();

	float getWalkSpeed();

	float getTerrainNegotiation();

	float getRunAcceleration();

	float getWalkAcceleration();

	int getLevel();

	String getPerformanceAnimation();

	String getMoodString();

	unsigned long long getWeaponID();

	unsigned long long getGroupID();

	unsigned long long getGroupInviterID();

	unsigned long long getGroupInviteCounter();

	int getGuildID();

	unsigned long long getTargetID();

	byte getMoodID();

	float getSlopeModPercent();

	int getPerformanceCounter();

	int getInstrumentID();

	byte getFrozen();

	float getHeight();

	int getSpecies();

	void setHeight(float heigh);

	void setWeaponID(unsigned long long objectID, bool notifyClient = false);

	void setTargetID(unsigned long long targetID, bool notifyClient = false);

	CreatureObject* _this;

	operator const CreatureObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~CreatureObjectImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class CreatureObject;
};

class CreatureObjectAdapter : public TangibleObjectAdapter {
public:
	CreatureObjectAdapter(CreatureObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void clearQueueAction(unsigned int actioncntr, float timer, unsigned int tab1, unsigned int tab2);

	void sendBaselinesTo(SceneObject* player);

	void sendSystemMessage(const String& message);

	void sendSystemMessage(UnicodeString& message);

	void sendSystemMessage(const String& file, const String& str, unsigned long long targetid);

	void sendSlottedObjectsTo(SceneObject* player);

	int getBankCredits();

	int getCashCredits();

	int getBaseHealth(int idx);

	unsigned int getBaseHealthUpdateCounter();

	int getWounds(int idx);

	unsigned int getWoundsUpdateCounter();

	unsigned int getEncumbrancesUpdateCounter();

	unsigned int getHamListUpdateCounter();

	int getHAM(int idx);

	unsigned int getMaxHamListUpdateCounter();

	int getMaxHAM(int idx);

	int getEncumbrance(int idx);

	byte getPosture();

	byte getFactionRank();

	unsigned long long getCreatureLinkID();

	float getShockWounds();

	unsigned long long getStateBitmask();

	unsigned long long getListenID();

	float getRunSpeed();

	float getWalkSpeed();

	float getTerrainNegotiation();

	float getRunAcceleration();

	float getWalkAcceleration();

	int getLevel();

	String getPerformanceAnimation();

	String getMoodString();

	unsigned long long getWeaponID();

	unsigned long long getGroupID();

	unsigned long long getGroupInviterID();

	unsigned long long getGroupInviteCounter();

	int getGuildID();

	unsigned long long getTargetID();

	byte getMoodID();

	float getSlopeModPercent();

	int getPerformanceCounter();

	int getInstrumentID();

	byte getFrozen();

	float getHeight();

	int getSpecies();

	void setHeight(float heigh);

	void setWeaponID(unsigned long long objectID, bool notifyClient);

	void setTargetID(unsigned long long targetID, bool notifyClient);

protected:
	String _param0_sendSystemMessage__String_;
	UnicodeString _param0_sendSystemMessage__UnicodeString_;
	String _param0_sendSystemMessage__String_String_long_;
	String _param1_sendSystemMessage__String_String_long_;
};

class CreatureObjectHelper : public DistributedObjectClassHelper, public Singleton<CreatureObjectHelper> {
	static CreatureObjectHelper* staticInitializer;

public:
	CreatureObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<CreatureObjectHelper>;
};

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

#endif /*CREATUREOBJECT_H_*/
