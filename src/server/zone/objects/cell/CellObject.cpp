/*
 *	server/zone/objects/cell/CellObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "CellObject.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"

/*
 *	CellObjectStub
 */

CellObject::CellObject() : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new CellObjectImplementation();
	_impl->_setStub(this);
}

CellObject::CellObject(DummyConstructorParameter* param) : SceneObject(param) {
}

CellObject::~CellObject() {
}


void CellObject::loadTemplateData(SharedObjectTemplate* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((CellObjectImplementation*) _impl)->loadTemplateData(templateData);
}

void CellObject::sendContainerObjectsTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->sendContainerObjectsTo(player);
}

void CellObject::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->initializeTransientMembers();
}

void CellObject::sendBaselinesTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->sendBaselinesTo(player);
}

int CellObject::getCellNumber() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithSignedIntReturn();
	} else
		return ((CellObjectImplementation*) _impl)->getCellNumber();
}

void CellObject::setCellNumber(int number) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addSignedIntParameter(number);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->setCellNumber(number);
}

bool CellObject::isCellObject() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return ((CellObjectImplementation*) _impl)->isCellObject();
}

/*
 *	CellObjectImplementation
 */

CellObjectImplementation::CellObjectImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}

CellObjectImplementation::~CellObjectImplementation() {
	CellObjectImplementation::finalize();
}


void CellObjectImplementation::_initializeImplementation() {
	_setClassHelper(CellObjectHelper::instance());

	_serializationHelperMethod();
}

void CellObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (CellObject*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* CellObjectImplementation::_getStub() {
	return _this;
}

CellObjectImplementation::operator const CellObject*() {
	return _this;
}

void CellObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void CellObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void CellObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void CellObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void CellObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void CellObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void CellObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void CellObjectImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("CellObject");

	addSerializableVariable("cellNumber", &cellNumber);
}

CellObjectImplementation::CellObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/cell/CellObject.idl(57):  		Logger.setLoggingName("CellObject");
	Logger::setLoggingName("CellObject");
	// server/zone/objects/cell/CellObject.idl(59):  		cellNumber = 0;
	cellNumber = 0;
}

void CellObjectImplementation::finalize() {
}

int CellObjectImplementation::getCellNumber() {
	// server/zone/objects/cell/CellObject.idl(81):  		return cellNumber;
	return cellNumber;
}

void CellObjectImplementation::setCellNumber(int number) {
	// server/zone/objects/cell/CellObject.idl(85):  		cellNumber = number;
	cellNumber = number;
}

bool CellObjectImplementation::isCellObject() {
	// server/zone/objects/cell/CellObject.idl(89):  		return true;
	return true;
}

/*
 *	CellObjectAdapter
 */

CellObjectAdapter::CellObjectAdapter(CellObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* CellObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendContainerObjectsTo((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		initializeTransientMembers();
		break;
	case 8:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 9:
		finalize();
		break;
	case 10:
		resp->insertSignedInt(getCellNumber());
		break;
	case 11:
		setCellNumber(inv->getSignedIntParameter());
		break;
	case 12:
		resp->insertBoolean(isCellObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CellObjectAdapter::sendContainerObjectsTo(SceneObject* player) {
	((CellObjectImplementation*) impl)->sendContainerObjectsTo(player);
}

void CellObjectAdapter::initializeTransientMembers() {
	((CellObjectImplementation*) impl)->initializeTransientMembers();
}

void CellObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((CellObjectImplementation*) impl)->sendBaselinesTo(player);
}

void CellObjectAdapter::finalize() {
	((CellObjectImplementation*) impl)->finalize();
}

int CellObjectAdapter::getCellNumber() {
	return ((CellObjectImplementation*) impl)->getCellNumber();
}

void CellObjectAdapter::setCellNumber(int number) {
	((CellObjectImplementation*) impl)->setCellNumber(number);
}

bool CellObjectAdapter::isCellObject() {
	return ((CellObjectImplementation*) impl)->isCellObject();
}

/*
 *	CellObjectHelper
 */

CellObjectHelper* CellObjectHelper::staticInitializer = CellObjectHelper::instance();

CellObjectHelper::CellObjectHelper() {
	className = "CellObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CellObjectHelper::finalizeHelper() {
	CellObjectHelper::finalize();
}

DistributedObject* CellObjectHelper::instantiateObject() {
	return new CellObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* CellObjectHelper::instantiateServant() {
	return new CellObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CellObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CellObjectAdapter((CellObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

