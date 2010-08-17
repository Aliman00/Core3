/*
 *	server/zone/managers/player/PlayerManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLAYERMANAGER_H_
#define PLAYERMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {

class ZoneProcessServerImplementation;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace managers {
namespace object {

class ObjectManager;

} // namespace object
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::object;

namespace server {
namespace zone {
namespace packets {

class MessageCallback;

} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace wearables {

class ArmorObject;

} // namespace wearables
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::wearables;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class Observable;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/player/PlayerMap.h"

#include "server/zone/managers/player/CharacterNameMap.h"

#include "server/zone/managers/player/StartingItemList.h"

#include "server/zone/objects/tangible/DamageMap.h"

#include "engine/log/Logger.h"

#include "engine/lua/Lua.h"

#include "system/util/VectorMap.h"

#include "engine/core/ManagedObject.h"

#include "server/zone/objects/scene/Observer.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class PlayerManager : public Observer {
public:
	PlayerManager(ZoneServer* zoneServer, ZoneProcessServerImplementation* impl);

	void loadNameMap();

	bool createPlayer(MessageCallback* callback);

	bool checkPlayerName(MessageCallback* callback);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	int notifyDestruction(TangibleObject* destructor, TangibleObject* destructedObject, int condition);

	int notifyDefendersOfIncapacitation(TangibleObject* destructor, TangibleObject* destructedObject);

	void killPlayer(TangibleObject* attacker, PlayerCreature* player);

	byte calculateIncapacitationTimer(PlayerCreature* player, int condition);

	bool checkEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void applyEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void removeEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void awardBadge(PlayerCreature* player, unsigned int badge);

	void setExperienceMultiplier(float globalMultiplier);

	void awardExperience(PlayerCreature* player, const String& xpType, int amount, bool sendSystemMessage = true, float localMultiplier = 1.0f);

	void handleAbortTradeMessage(PlayerCreature* player, bool doLock = true);

	void handleAddItemToTradeWindow(PlayerCreature* player, unsigned long long itemID);

	void handleGiveMoneyMessage(PlayerCreature* player, unsigned int value);

	void handleAcceptTransactionMessage(PlayerCreature* player);

	void handleUnAcceptTransactionMessage(PlayerCreature* player);

	void handleVerifyTradeMessage(PlayerCreature* player);

	bool checkTradeItems(PlayerCreature* player, PlayerCreature* receiver);

	void sendBattleFatigueMessage(PlayerCreature* player, PlayerCreature* target);

	int getMedicalFacilityRating(CreatureObject* creature);

	int healEnhance(CreatureObject* enhancer, CreatureObject* patient, byte attribute, int buffvalue, float duration);

	void disseminateExperience(TangibleObject* destructedObject, DamageMap* damageMap);

	void sendMessageOfTheDay(PlayerCreature* player);

	void sendActivateCloneRequest(PlayerCreature* player);

	void sendPlayerToCloner(PlayerCreature* player, unsigned long long clonerID);

	bool checkExistentNameInDatabase(const String& firstName);

	TangibleObject* createHairObject(const String& hairObjectFile, const String& hairCustomization);

	bool createAllPlayerObjects(PlayerCreature* player);

	void createDefaultPlayerItems(PlayerCreature* player, const String& profession, const String& templateFile);

	void createTutorialBuilding(PlayerCreature* player);

	void createSkippedTutorialBuilding(PlayerCreature* player);

	bool existsName(const String& name);

	unsigned long long getObjectID(const String& name);

	PlayerCreature* getPlayer(const String& name);

protected:
	PlayerManager(DummyConstructorParameter* param);

	virtual ~PlayerManager();

	friend class PlayerManagerHelper;
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

namespace server {
namespace zone {
namespace managers {
namespace player {

class PlayerManagerImplementation : public ObserverImplementation, public Logger {
	ZoneProcessServerImplementation* processor;

	ManagedReference<ZoneServer* > server;

	PlayerMap* playerMap;

	CharacterNameMap* nameMap;

	float globalExpMultiplier;

public:
	StartingItemList* startingItemList;

	PlayerManagerImplementation(ZoneServer* zoneServer, ZoneProcessServerImplementation* impl);

	PlayerManagerImplementation(DummyConstructorParameter* param);

	void loadNameMap();

private:
	void loadStartingItems();

public:
	void finalize();

	bool createPlayer(MessageCallback* callback);

	bool checkPlayerName(MessageCallback* callback);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	int notifyDestruction(TangibleObject* destructor, TangibleObject* destructedObject, int condition);

	int notifyDefendersOfIncapacitation(TangibleObject* destructor, TangibleObject* destructedObject);

	void killPlayer(TangibleObject* attacker, PlayerCreature* player);

	byte calculateIncapacitationTimer(PlayerCreature* player, int condition);

	bool checkEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void applyEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void removeEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void awardBadge(PlayerCreature* player, unsigned int badge);

	void setExperienceMultiplier(float globalMultiplier);

	void awardExperience(PlayerCreature* player, const String& xpType, int amount, bool sendSystemMessage = true, float localMultiplier = 1.0f);

	void handleAbortTradeMessage(PlayerCreature* player, bool doLock = true);

	void handleAddItemToTradeWindow(PlayerCreature* player, unsigned long long itemID);

	void handleGiveMoneyMessage(PlayerCreature* player, unsigned int value);

	void handleAcceptTransactionMessage(PlayerCreature* player);

	void handleUnAcceptTransactionMessage(PlayerCreature* player);

	void handleVerifyTradeMessage(PlayerCreature* player);

	bool checkTradeItems(PlayerCreature* player, PlayerCreature* receiver);

	void sendBattleFatigueMessage(PlayerCreature* player, PlayerCreature* target);

	int getMedicalFacilityRating(CreatureObject* creature);

	int healEnhance(CreatureObject* enhancer, CreatureObject* patient, byte attribute, int buffvalue, float duration);

	void disseminateExperience(TangibleObject* destructedObject, DamageMap* damageMap);

	void sendMessageOfTheDay(PlayerCreature* player);

	void sendActivateCloneRequest(PlayerCreature* player);

	void sendPlayerToCloner(PlayerCreature* player, unsigned long long clonerID);

	bool checkExistentNameInDatabase(const String& firstName);

	TangibleObject* createHairObject(const String& hairObjectFile, const String& hairCustomization);

	bool createAllPlayerObjects(PlayerCreature* player);

	void createDefaultPlayerItems(PlayerCreature* player, const String& profession, const String& templateFile);

	void createTutorialBuilding(PlayerCreature* player);

	void createSkippedTutorialBuilding(PlayerCreature* player);

	bool existsName(const String& name);

	unsigned long long getObjectID(const String& name);

	PlayerCreature* getPlayer(const String& name);

	PlayerManager* _this;

	operator const PlayerManager*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~PlayerManagerImplementation();

	TransactionalObject* clone();

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

	friend class PlayerManager;
	friend class TransactionalObjectHandle<PlayerManagerImplementation*>;
};

class PlayerManagerAdapter : public ObserverAdapter {
public:
	PlayerManagerAdapter(PlayerManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void loadNameMap();

	void finalize();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	int notifyDestruction(TangibleObject* destructor, TangibleObject* destructedObject, int condition);

	int notifyDefendersOfIncapacitation(TangibleObject* destructor, TangibleObject* destructedObject);

	void killPlayer(TangibleObject* attacker, PlayerCreature* player);

	byte calculateIncapacitationTimer(PlayerCreature* player, int condition);

	bool checkEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void applyEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void removeEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void awardBadge(PlayerCreature* player, unsigned int badge);

	void setExperienceMultiplier(float globalMultiplier);

	void awardExperience(PlayerCreature* player, const String& xpType, int amount, bool sendSystemMessage, float localMultiplier);

	void handleAbortTradeMessage(PlayerCreature* player, bool doLock);

	void handleAddItemToTradeWindow(PlayerCreature* player, unsigned long long itemID);

	void handleGiveMoneyMessage(PlayerCreature* player, unsigned int value);

	void handleAcceptTransactionMessage(PlayerCreature* player);

	void handleUnAcceptTransactionMessage(PlayerCreature* player);

	void handleVerifyTradeMessage(PlayerCreature* player);

	bool checkTradeItems(PlayerCreature* player, PlayerCreature* receiver);

	void sendBattleFatigueMessage(PlayerCreature* player, PlayerCreature* target);

	int getMedicalFacilityRating(CreatureObject* creature);

	int healEnhance(CreatureObject* enhancer, CreatureObject* patient, byte attribute, int buffvalue, float duration);

	void sendMessageOfTheDay(PlayerCreature* player);

	void sendActivateCloneRequest(PlayerCreature* player);

	void sendPlayerToCloner(PlayerCreature* player, unsigned long long clonerID);

	bool checkExistentNameInDatabase(const String& firstName);

	TangibleObject* createHairObject(const String& hairObjectFile, const String& hairCustomization);

	bool createAllPlayerObjects(PlayerCreature* player);

	void createDefaultPlayerItems(PlayerCreature* player, const String& profession, const String& templateFile);

	void createTutorialBuilding(PlayerCreature* player);

	void createSkippedTutorialBuilding(PlayerCreature* player);

	bool existsName(const String& name);

	unsigned long long getObjectID(const String& name);

	PlayerCreature* getPlayer(const String& name);

protected:
	String _param1_awardExperience__PlayerCreature_String_int_bool_float_;
	String _param0_checkExistentNameInDatabase__String_;
	String _param0_createHairObject__String_String_;
	String _param1_createHairObject__String_String_;
	String _param1_createDefaultPlayerItems__PlayerCreature_String_String_;
	String _param2_createDefaultPlayerItems__PlayerCreature_String_String_;
	String _param0_existsName__String_;
	String _param0_getObjectID__String_;
	String _param0_getPlayer__String_;
};

class PlayerManagerHelper : public DistributedObjectClassHelper, public Singleton<PlayerManagerHelper> {
	static PlayerManagerHelper* staticInitializer;

public:
	PlayerManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlayerManagerHelper>;
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

#endif /*PLAYERMANAGER_H_*/
