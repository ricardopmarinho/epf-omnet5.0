//
// Generated file, do not edit! Created by nedtool 5.0 from inet/routing/epf/EPFControlPackets.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "EPFControlPackets_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::EPFControlPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::EPFControlPacketType"));
    e->insert(Enquire, "Enquire");
    e->insert(Response, "Response");
    e->insert(Data, "Data");
    e->insert(ContactInfoMsg, "ContactInfoMsg");
);

Register_Class(EPFControlPacket);

EPFControlPacket::EPFControlPacket(const char *name, int kind) : ::inet::AODVControlPacket(name,kind)
{
}

EPFControlPacket::EPFControlPacket(const EPFControlPacket& other) : ::inet::AODVControlPacket(other)
{
    copy(other);
}

EPFControlPacket::~EPFControlPacket()
{
}

EPFControlPacket& EPFControlPacket::operator=(const EPFControlPacket& other)
{
    if (this==&other) return *this;
    ::inet::AODVControlPacket::operator=(other);
    copy(other);
    return *this;
}

void EPFControlPacket::copy(const EPFControlPacket& other)
{
}

void EPFControlPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVControlPacket::parsimPack(b);
}

void EPFControlPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVControlPacket::parsimUnpack(b);
}

class EPFControlPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EPFControlPacketDescriptor();
    virtual ~EPFControlPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EPFControlPacketDescriptor);

EPFControlPacketDescriptor::EPFControlPacketDescriptor() : omnetpp::cClassDescriptor("inet::EPFControlPacket", "inet::AODVControlPacket")
{
    propertynames = nullptr;
}

EPFControlPacketDescriptor::~EPFControlPacketDescriptor()
{
    delete[] propertynames;
}

bool EPFControlPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EPFControlPacket *>(obj)!=nullptr;
}

const char **EPFControlPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EPFControlPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EPFControlPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int EPFControlPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *EPFControlPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int EPFControlPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EPFControlPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **EPFControlPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EPFControlPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EPFControlPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EPFControlPacket *pp = (EPFControlPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EPFControlPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EPFControlPacket *pp = (EPFControlPacket *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool EPFControlPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EPFControlPacket *pp = (EPFControlPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *EPFControlPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *EPFControlPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EPFControlPacket *pp = (EPFControlPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(EPFRREQ);

EPFRREQ::EPFRREQ(const char *name) : ::inet::EPFControlPacket(name)
{
    this->packetType = RREQ;
    this->joinFlag = false;
    this->repairFlag = false;
    this->gratuitousRREPFlag = false;
    this->destOnlyFlag = false;
    this->unknownSeqNumFlag = false;
    this->hopCount = 0;
    this->rreqId = 0;
    this->destSeqNum = 0;
    this->originatorSeqNum = 0;
}

EPFRREQ::EPFRREQ(const EPFRREQ& other) : ::inet::EPFControlPacket(other)
{
    copy(other);
}

EPFRREQ::~EPFRREQ()
{
}

EPFRREQ& EPFRREQ::operator=(const EPFRREQ& other)
{
    if (this==&other) return *this;
    ::inet::EPFControlPacket::operator=(other);
    copy(other);
    return *this;
}

void EPFRREQ::copy(const EPFRREQ& other)
{
    this->packetType = other.packetType;
    this->joinFlag = other.joinFlag;
    this->repairFlag = other.repairFlag;
    this->gratuitousRREPFlag = other.gratuitousRREPFlag;
    this->destOnlyFlag = other.destOnlyFlag;
    this->unknownSeqNumFlag = other.unknownSeqNumFlag;
    this->hopCount = other.hopCount;
    this->rreqId = other.rreqId;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->originatorSeqNum = other.originatorSeqNum;
}

void EPFRREQ::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EPFControlPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->joinFlag);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->gratuitousRREPFlag);
    doParsimPacking(b,this->destOnlyFlag);
    doParsimPacking(b,this->unknownSeqNumFlag);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->rreqId);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->originatorSeqNum);
}

void EPFRREQ::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EPFControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->joinFlag);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->gratuitousRREPFlag);
    doParsimUnpacking(b,this->destOnlyFlag);
    doParsimUnpacking(b,this->unknownSeqNumFlag);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->rreqId);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->originatorSeqNum);
}

unsigned int EPFRREQ::getPacketType() const
{
    return this->packetType;
}

void EPFRREQ::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

bool EPFRREQ::getJoinFlag() const
{
    return this->joinFlag;
}

void EPFRREQ::setJoinFlag(bool joinFlag)
{
    this->joinFlag = joinFlag;
}

bool EPFRREQ::getRepairFlag() const
{
    return this->repairFlag;
}

void EPFRREQ::setRepairFlag(bool repairFlag)
{
    this->repairFlag = repairFlag;
}

bool EPFRREQ::getGratuitousRREPFlag() const
{
    return this->gratuitousRREPFlag;
}

void EPFRREQ::setGratuitousRREPFlag(bool gratuitousRREPFlag)
{
    this->gratuitousRREPFlag = gratuitousRREPFlag;
}

bool EPFRREQ::getDestOnlyFlag() const
{
    return this->destOnlyFlag;
}

void EPFRREQ::setDestOnlyFlag(bool destOnlyFlag)
{
    this->destOnlyFlag = destOnlyFlag;
}

bool EPFRREQ::getUnknownSeqNumFlag() const
{
    return this->unknownSeqNumFlag;
}

void EPFRREQ::setUnknownSeqNumFlag(bool unknownSeqNumFlag)
{
    this->unknownSeqNumFlag = unknownSeqNumFlag;
}

unsigned int EPFRREQ::getHopCount() const
{
    return this->hopCount;
}

void EPFRREQ::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

unsigned int EPFRREQ::getRreqId() const
{
    return this->rreqId;
}

void EPFRREQ::setRreqId(unsigned int rreqId)
{
    this->rreqId = rreqId;
}

L3Address& EPFRREQ::getDestAddr()
{
    return this->destAddr;
}

void EPFRREQ::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int EPFRREQ::getDestSeqNum() const
{
    return this->destSeqNum;
}

void EPFRREQ::setDestSeqNum(unsigned int destSeqNum)
{
    this->destSeqNum = destSeqNum;
}

L3Address& EPFRREQ::getOriginatorAddr()
{
    return this->originatorAddr;
}

void EPFRREQ::setOriginatorAddr(const L3Address& originatorAddr)
{
    this->originatorAddr = originatorAddr;
}

unsigned int EPFRREQ::getOriginatorSeqNum() const
{
    return this->originatorSeqNum;
}

void EPFRREQ::setOriginatorSeqNum(unsigned int originatorSeqNum)
{
    this->originatorSeqNum = originatorSeqNum;
}

class EPFRREQDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EPFRREQDescriptor();
    virtual ~EPFRREQDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EPFRREQDescriptor);

EPFRREQDescriptor::EPFRREQDescriptor() : omnetpp::cClassDescriptor("inet::EPFRREQ", "inet::EPFControlPacket")
{
    propertynames = nullptr;
}

EPFRREQDescriptor::~EPFRREQDescriptor()
{
    delete[] propertynames;
}

bool EPFRREQDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EPFRREQ *>(obj)!=nullptr;
}

const char **EPFRREQDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EPFRREQDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EPFRREQDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int EPFRREQDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *EPFRREQDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "joinFlag",
        "repairFlag",
        "gratuitousRREPFlag",
        "destOnlyFlag",
        "unknownSeqNumFlag",
        "hopCount",
        "rreqId",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
    };
    return (field>=0 && field<12) ? fieldNames[field] : nullptr;
}

int EPFRREQDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinFlag")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "repairFlag")==0) return base+2;
    if (fieldName[0]=='g' && strcmp(fieldName, "gratuitousRREPFlag")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destOnlyFlag")==0) return base+4;
    if (fieldName[0]=='u' && strcmp(fieldName, "unknownSeqNumFlag")==0) return base+5;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "rreqId")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSeqNum")==0) return base+9;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddr")==0) return base+10;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorSeqNum")==0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EPFRREQDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "L3Address",
        "unsigned int",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : nullptr;
}

const char **EPFRREQDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EPFRREQDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EPFRREQDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EPFRREQ *pp = (EPFRREQ *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EPFRREQDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EPFRREQ *pp = (EPFRREQ *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return bool2string(pp->getJoinFlag());
        case 2: return bool2string(pp->getRepairFlag());
        case 3: return bool2string(pp->getGratuitousRREPFlag());
        case 4: return bool2string(pp->getDestOnlyFlag());
        case 5: return bool2string(pp->getUnknownSeqNumFlag());
        case 6: return ulong2string(pp->getHopCount());
        case 7: return ulong2string(pp->getRreqId());
        case 8: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 9: return ulong2string(pp->getDestSeqNum());
        case 10: {std::stringstream out; out << pp->getOriginatorAddr(); return out.str();}
        case 11: return ulong2string(pp->getOriginatorSeqNum());
        default: return "";
    }
}

bool EPFRREQDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EPFRREQ *pp = (EPFRREQ *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setJoinFlag(string2bool(value)); return true;
        case 2: pp->setRepairFlag(string2bool(value)); return true;
        case 3: pp->setGratuitousRREPFlag(string2bool(value)); return true;
        case 4: pp->setDestOnlyFlag(string2bool(value)); return true;
        case 5: pp->setUnknownSeqNumFlag(string2bool(value)); return true;
        case 6: pp->setHopCount(string2ulong(value)); return true;
        case 7: pp->setRreqId(string2ulong(value)); return true;
        case 9: pp->setDestSeqNum(string2ulong(value)); return true;
        case 11: pp->setOriginatorSeqNum(string2ulong(value)); return true;
        default: return false;
    }
}

const char *EPFRREQDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 8: return omnetpp::opp_typename(typeid(L3Address));
        case 10: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *EPFRREQDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EPFRREQ *pp = (EPFRREQ *)object; (void)pp;
    switch (field) {
        case 8: return (void *)(&pp->getDestAddr()); break;
        case 10: return (void *)(&pp->getOriginatorAddr()); break;
        default: return nullptr;
    }
}

Register_Class(EPFRREP);

EPFRREP::EPFRREP(const char *name) : ::inet::EPFControlPacket(name)
{
    this->packetType = RREP;
    this->repairFlag = false;
    this->ackRequiredFlag = false;
    this->prefixSize = 0;
    this->hopCount = 0;
    this->destSeqNum = 0;
    this->originatorSeqNum = 0;
    this->lifeTime = 0;
}

EPFRREP::EPFRREP(const EPFRREP& other) : ::inet::EPFControlPacket(other)
{
    copy(other);
}

EPFRREP::~EPFRREP()
{
}

EPFRREP& EPFRREP::operator=(const EPFRREP& other)
{
    if (this==&other) return *this;
    ::inet::EPFControlPacket::operator=(other);
    copy(other);
    return *this;
}

void EPFRREP::copy(const EPFRREP& other)
{
    this->packetType = other.packetType;
    this->repairFlag = other.repairFlag;
    this->ackRequiredFlag = other.ackRequiredFlag;
    this->prefixSize = other.prefixSize;
    this->hopCount = other.hopCount;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->originatorSeqNum = other.originatorSeqNum;
    this->lifeTime = other.lifeTime;
}

void EPFRREP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EPFControlPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->ackRequiredFlag);
    doParsimPacking(b,this->prefixSize);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->originatorSeqNum);
    doParsimPacking(b,this->lifeTime);
}

void EPFRREP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EPFControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->ackRequiredFlag);
    doParsimUnpacking(b,this->prefixSize);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->originatorSeqNum);
    doParsimUnpacking(b,this->lifeTime);
}

unsigned int EPFRREP::getPacketType() const
{
    return this->packetType;
}

void EPFRREP::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

bool EPFRREP::getRepairFlag() const
{
    return this->repairFlag;
}

void EPFRREP::setRepairFlag(bool repairFlag)
{
    this->repairFlag = repairFlag;
}

bool EPFRREP::getAckRequiredFlag() const
{
    return this->ackRequiredFlag;
}

void EPFRREP::setAckRequiredFlag(bool ackRequiredFlag)
{
    this->ackRequiredFlag = ackRequiredFlag;
}

unsigned int EPFRREP::getPrefixSize() const
{
    return this->prefixSize;
}

void EPFRREP::setPrefixSize(unsigned int prefixSize)
{
    this->prefixSize = prefixSize;
}

unsigned int EPFRREP::getHopCount() const
{
    return this->hopCount;
}

void EPFRREP::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

L3Address& EPFRREP::getDestAddr()
{
    return this->destAddr;
}

void EPFRREP::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int EPFRREP::getDestSeqNum() const
{
    return this->destSeqNum;
}

void EPFRREP::setDestSeqNum(unsigned int destSeqNum)
{
    this->destSeqNum = destSeqNum;
}

L3Address& EPFRREP::getOriginatorAddr()
{
    return this->originatorAddr;
}

void EPFRREP::setOriginatorAddr(const L3Address& originatorAddr)
{
    this->originatorAddr = originatorAddr;
}

unsigned int EPFRREP::getOriginatorSeqNum() const
{
    return this->originatorSeqNum;
}

void EPFRREP::setOriginatorSeqNum(unsigned int originatorSeqNum)
{
    this->originatorSeqNum = originatorSeqNum;
}

::omnetpp::simtime_t EPFRREP::getLifeTime() const
{
    return this->lifeTime;
}

void EPFRREP::setLifeTime(::omnetpp::simtime_t lifeTime)
{
    this->lifeTime = lifeTime;
}

class EPFRREPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EPFRREPDescriptor();
    virtual ~EPFRREPDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EPFRREPDescriptor);

EPFRREPDescriptor::EPFRREPDescriptor() : omnetpp::cClassDescriptor("inet::EPFRREP", "inet::EPFControlPacket")
{
    propertynames = nullptr;
}

EPFRREPDescriptor::~EPFRREPDescriptor()
{
    delete[] propertynames;
}

bool EPFRREPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EPFRREP *>(obj)!=nullptr;
}

const char **EPFRREPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EPFRREPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EPFRREPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int EPFRREPDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *EPFRREPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "repairFlag",
        "ackRequiredFlag",
        "prefixSize",
        "hopCount",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
        "lifeTime",
    };
    return (field>=0 && field<10) ? fieldNames[field] : nullptr;
}

int EPFRREPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "repairFlag")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackRequiredFlag")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixSize")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSeqNum")==0) return base+6;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddr")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorSeqNum")==0) return base+8;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifeTime")==0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EPFRREPDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "simtime_t",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : nullptr;
}

const char **EPFRREPDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EPFRREPDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EPFRREPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EPFRREP *pp = (EPFRREP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EPFRREPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EPFRREP *pp = (EPFRREP *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return bool2string(pp->getRepairFlag());
        case 2: return bool2string(pp->getAckRequiredFlag());
        case 3: return ulong2string(pp->getPrefixSize());
        case 4: return ulong2string(pp->getHopCount());
        case 5: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 6: return ulong2string(pp->getDestSeqNum());
        case 7: {std::stringstream out; out << pp->getOriginatorAddr(); return out.str();}
        case 8: return ulong2string(pp->getOriginatorSeqNum());
        case 9: return simtime2string(pp->getLifeTime());
        default: return "";
    }
}

bool EPFRREPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EPFRREP *pp = (EPFRREP *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setRepairFlag(string2bool(value)); return true;
        case 2: pp->setAckRequiredFlag(string2bool(value)); return true;
        case 3: pp->setPrefixSize(string2ulong(value)); return true;
        case 4: pp->setHopCount(string2ulong(value)); return true;
        case 6: pp->setDestSeqNum(string2ulong(value)); return true;
        case 8: pp->setOriginatorSeqNum(string2ulong(value)); return true;
        case 9: pp->setLifeTime(string2simtime(value)); return true;
        default: return false;
    }
}

const char *EPFRREPDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(L3Address));
        case 7: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *EPFRREPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EPFRREP *pp = (EPFRREP *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getDestAddr()); break;
        case 7: return (void *)(&pp->getOriginatorAddr()); break;
        default: return nullptr;
    }
}

Register_Class(EPFRERR);

EPFRERR::EPFRERR(const char *name) : ::inet::EPFControlPacket(name)
{
    this->packetType = RERR;
    unreachableNodes_arraysize = 0;
    this->unreachableNodes = 0;
    this->noDeleteFlag = false;
    this->destCount = 0;
}

EPFRERR::EPFRERR(const EPFRERR& other) : ::inet::EPFControlPacket(other)
{
    unreachableNodes_arraysize = 0;
    this->unreachableNodes = 0;
    copy(other);
}

EPFRERR::~EPFRERR()
{
    delete [] this->unreachableNodes;
}

EPFRERR& EPFRERR::operator=(const EPFRERR& other)
{
    if (this==&other) return *this;
    ::inet::EPFControlPacket::operator=(other);
    copy(other);
    return *this;
}

void EPFRERR::copy(const EPFRERR& other)
{
    this->packetType = other.packetType;
    delete [] this->unreachableNodes;
    this->unreachableNodes = (other.unreachableNodes_arraysize==0) ? nullptr : new UnreachableNode[other.unreachableNodes_arraysize];
    unreachableNodes_arraysize = other.unreachableNodes_arraysize;
    for (unsigned int i=0; i<unreachableNodes_arraysize; i++)
        this->unreachableNodes[i] = other.unreachableNodes[i];
    this->noDeleteFlag = other.noDeleteFlag;
    this->destCount = other.destCount;
}

void EPFRERR::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EPFControlPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    b->pack(unreachableNodes_arraysize);
    doParsimArrayPacking(b,this->unreachableNodes,unreachableNodes_arraysize);
    doParsimPacking(b,this->noDeleteFlag);
    doParsimPacking(b,this->destCount);
}

void EPFRERR::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EPFControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    delete [] this->unreachableNodes;
    b->unpack(unreachableNodes_arraysize);
    if (unreachableNodes_arraysize==0) {
        this->unreachableNodes = 0;
    } else {
        this->unreachableNodes = new UnreachableNode[unreachableNodes_arraysize];
        doParsimArrayUnpacking(b,this->unreachableNodes,unreachableNodes_arraysize);
    }
    doParsimUnpacking(b,this->noDeleteFlag);
    doParsimUnpacking(b,this->destCount);
}

unsigned int EPFRERR::getPacketType() const
{
    return this->packetType;
}

void EPFRERR::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

void EPFRERR::setUnreachableNodesArraySize(unsigned int size)
{
    UnreachableNode *unreachableNodes2 = (size==0) ? nullptr : new UnreachableNode[size];
    unsigned int sz = unreachableNodes_arraysize < size ? unreachableNodes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    unreachableNodes_arraysize = size;
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
}

unsigned int EPFRERR::getUnreachableNodesArraySize() const
{
    return unreachableNodes_arraysize;
}

UnreachableNode& EPFRERR::getUnreachableNodes(unsigned int k)
{
    if (k>=unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableNodes_arraysize, k);
    return this->unreachableNodes[k];
}

void EPFRERR::setUnreachableNodes(unsigned int k, const UnreachableNode& unreachableNodes)
{
    if (k>=unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableNodes_arraysize, k);
    this->unreachableNodes[k] = unreachableNodes;
}

bool EPFRERR::getNoDeleteFlag() const
{
    return this->noDeleteFlag;
}

void EPFRERR::setNoDeleteFlag(bool noDeleteFlag)
{
    this->noDeleteFlag = noDeleteFlag;
}

unsigned int EPFRERR::getDestCount() const
{
    return this->destCount;
}

void EPFRERR::setDestCount(unsigned int destCount)
{
    this->destCount = destCount;
}

class EPFRERRDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EPFRERRDescriptor();
    virtual ~EPFRERRDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EPFRERRDescriptor);

EPFRERRDescriptor::EPFRERRDescriptor() : omnetpp::cClassDescriptor("inet::EPFRERR", "inet::EPFControlPacket")
{
    propertynames = nullptr;
}

EPFRERRDescriptor::~EPFRERRDescriptor()
{
    delete[] propertynames;
}

bool EPFRERRDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EPFRERR *>(obj)!=nullptr;
}

const char **EPFRERRDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EPFRERRDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EPFRERRDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int EPFRERRDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *EPFRERRDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "unreachableNodes",
        "noDeleteFlag",
        "destCount",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int EPFRERRDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "unreachableNodes")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "noDeleteFlag")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destCount")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EPFRERRDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "UnreachableNode",
        "bool",
        "unsigned int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **EPFRERRDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EPFRERRDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EPFRERRDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EPFRERR *pp = (EPFRERR *)object; (void)pp;
    switch (field) {
        case 1: return pp->getUnreachableNodesArraySize();
        default: return 0;
    }
}

std::string EPFRERRDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EPFRERR *pp = (EPFRERR *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: {std::stringstream out; out << pp->getUnreachableNodes(i); return out.str();}
        case 2: return bool2string(pp->getNoDeleteFlag());
        case 3: return ulong2string(pp->getDestCount());
        default: return "";
    }
}

bool EPFRERRDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EPFRERR *pp = (EPFRERR *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 2: pp->setNoDeleteFlag(string2bool(value)); return true;
        case 3: pp->setDestCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *EPFRERRDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(UnreachableNode));
        default: return nullptr;
    };
}

void *EPFRERRDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EPFRERR *pp = (EPFRERR *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getUnreachableNodes(i)); break;
        default: return nullptr;
    }
}

Register_Class(EPFRREPACK);

EPFRREPACK::EPFRREPACK(const char *name) : ::inet::EPFControlPacket(name)
{
    this->packetType = RREPACK;
}

EPFRREPACK::EPFRREPACK(const EPFRREPACK& other) : ::inet::EPFControlPacket(other)
{
    copy(other);
}

EPFRREPACK::~EPFRREPACK()
{
}

EPFRREPACK& EPFRREPACK::operator=(const EPFRREPACK& other)
{
    if (this==&other) return *this;
    ::inet::EPFControlPacket::operator=(other);
    copy(other);
    return *this;
}

void EPFRREPACK::copy(const EPFRREPACK& other)
{
    this->packetType = other.packetType;
}

void EPFRREPACK::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EPFControlPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
}

void EPFRREPACK::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EPFControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
}

unsigned int EPFRREPACK::getPacketType() const
{
    return this->packetType;
}

void EPFRREPACK::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

class EPFRREPACKDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EPFRREPACKDescriptor();
    virtual ~EPFRREPACKDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EPFRREPACKDescriptor);

EPFRREPACKDescriptor::EPFRREPACKDescriptor() : omnetpp::cClassDescriptor("inet::EPFRREPACK", "inet::EPFControlPacket")
{
    propertynames = nullptr;
}

EPFRREPACKDescriptor::~EPFRREPACKDescriptor()
{
    delete[] propertynames;
}

bool EPFRREPACKDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EPFRREPACK *>(obj)!=nullptr;
}

const char **EPFRREPACKDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EPFRREPACKDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EPFRREPACKDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int EPFRREPACKDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *EPFRREPACKDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int EPFRREPACKDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EPFRREPACKDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **EPFRREPACKDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EPFRREPACKDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EPFRREPACKDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EPFRREPACK *pp = (EPFRREPACK *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EPFRREPACKDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EPFRREPACK *pp = (EPFRREPACK *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        default: return "";
    }
}

bool EPFRREPACKDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EPFRREPACK *pp = (EPFRREPACK *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *EPFRREPACKDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *EPFRREPACKDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EPFRREPACK *pp = (EPFRREPACK *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CONTACTINFOMSG);

CONTACTINFOMSG::CONTACTINFOMSG(const char *name) : ::inet::EPFControlPacket(name)
{
    this->packetType = ContactInfoMsg;
    this->hostIndex = 0;
}

CONTACTINFOMSG::CONTACTINFOMSG(const CONTACTINFOMSG& other) : ::inet::EPFControlPacket(other)
{
    copy(other);
}

CONTACTINFOMSG::~CONTACTINFOMSG()
{
}

CONTACTINFOMSG& CONTACTINFOMSG::operator=(const CONTACTINFOMSG& other)
{
    if (this==&other) return *this;
    ::inet::EPFControlPacket::operator=(other);
    copy(other);
    return *this;
}

void CONTACTINFOMSG::copy(const CONTACTINFOMSG& other)
{
    this->packetType = other.packetType;
    this->hostIndex = other.hostIndex;
    this->sourceAddr = other.sourceAddr;
}

void CONTACTINFOMSG::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EPFControlPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->hostIndex);
    doParsimPacking(b,this->sourceAddr);
}

void CONTACTINFOMSG::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EPFControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->hostIndex);
    doParsimUnpacking(b,this->sourceAddr);
}

unsigned int CONTACTINFOMSG::getPacketType() const
{
    return this->packetType;
}

void CONTACTINFOMSG::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

unsigned int CONTACTINFOMSG::getHostIndex() const
{
    return this->hostIndex;
}

void CONTACTINFOMSG::setHostIndex(unsigned int hostIndex)
{
    this->hostIndex = hostIndex;
}

L3Address& CONTACTINFOMSG::getSourceAddr()
{
    return this->sourceAddr;
}

void CONTACTINFOMSG::setSourceAddr(const L3Address& sourceAddr)
{
    this->sourceAddr = sourceAddr;
}

class CONTACTINFOMSGDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CONTACTINFOMSGDescriptor();
    virtual ~CONTACTINFOMSGDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CONTACTINFOMSGDescriptor);

CONTACTINFOMSGDescriptor::CONTACTINFOMSGDescriptor() : omnetpp::cClassDescriptor("inet::CONTACTINFOMSG", "inet::EPFControlPacket")
{
    propertynames = nullptr;
}

CONTACTINFOMSGDescriptor::~CONTACTINFOMSGDescriptor()
{
    delete[] propertynames;
}

bool CONTACTINFOMSGDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CONTACTINFOMSG *>(obj)!=nullptr;
}

const char **CONTACTINFOMSGDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CONTACTINFOMSGDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CONTACTINFOMSGDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int CONTACTINFOMSGDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *CONTACTINFOMSGDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "hostIndex",
        "sourceAddr",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int CONTACTINFOMSGDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hostIndex")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddr")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CONTACTINFOMSGDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "L3Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **CONTACTINFOMSGDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *CONTACTINFOMSGDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int CONTACTINFOMSGDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CONTACTINFOMSG *pp = (CONTACTINFOMSG *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string CONTACTINFOMSGDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CONTACTINFOMSG *pp = (CONTACTINFOMSG *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHostIndex());
        case 2: {std::stringstream out; out << pp->getSourceAddr(); return out.str();}
        default: return "";
    }
}

bool CONTACTINFOMSGDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CONTACTINFOMSG *pp = (CONTACTINFOMSG *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHostIndex(string2ulong(value)); return true;
        default: return false;
    }
}

const char *CONTACTINFOMSGDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *CONTACTINFOMSGDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CONTACTINFOMSG *pp = (CONTACTINFOMSG *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getSourceAddr()); break;
        default: return nullptr;
    }
}

Register_Class(EnquireMessage);

EnquireMessage::EnquireMessage(const char *name) : ::inet::EPFControlPacket(name)
{
    this->packetType = Enquire;
    this->hostIndex = 0;
    this->destIndex = 0;
    this->seqNum = 0;
    this->ownerIndex = 0;
    this->destContactDuration = 0;
}

EnquireMessage::EnquireMessage(const EnquireMessage& other) : ::inet::EPFControlPacket(other)
{
    copy(other);
}

EnquireMessage::~EnquireMessage()
{
}

EnquireMessage& EnquireMessage::operator=(const EnquireMessage& other)
{
    if (this==&other) return *this;
    ::inet::EPFControlPacket::operator=(other);
    copy(other);
    return *this;
}

void EnquireMessage::copy(const EnquireMessage& other)
{
    this->packetType = other.packetType;
    this->hostIndex = other.hostIndex;
    this->destIndex = other.destIndex;
    this->seqNum = other.seqNum;
    this->ownerIndex = other.ownerIndex;
    this->sourceAddr = other.sourceAddr;
    this->ownerAddr = other.ownerAddr;
    this->destAddr = other.destAddr;
    this->destContactDuration = other.destContactDuration;
}

void EnquireMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EPFControlPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->hostIndex);
    doParsimPacking(b,this->destIndex);
    doParsimPacking(b,this->seqNum);
    doParsimPacking(b,this->ownerIndex);
    doParsimPacking(b,this->sourceAddr);
    doParsimPacking(b,this->ownerAddr);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destContactDuration);
}

void EnquireMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EPFControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->hostIndex);
    doParsimUnpacking(b,this->destIndex);
    doParsimUnpacking(b,this->seqNum);
    doParsimUnpacking(b,this->ownerIndex);
    doParsimUnpacking(b,this->sourceAddr);
    doParsimUnpacking(b,this->ownerAddr);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destContactDuration);
}

unsigned int EnquireMessage::getPacketType() const
{
    return this->packetType;
}

void EnquireMessage::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

unsigned int EnquireMessage::getHostIndex() const
{
    return this->hostIndex;
}

void EnquireMessage::setHostIndex(unsigned int hostIndex)
{
    this->hostIndex = hostIndex;
}

unsigned int EnquireMessage::getDestIndex() const
{
    return this->destIndex;
}

void EnquireMessage::setDestIndex(unsigned int destIndex)
{
    this->destIndex = destIndex;
}

unsigned int EnquireMessage::getSeqNum() const
{
    return this->seqNum;
}

void EnquireMessage::setSeqNum(unsigned int seqNum)
{
    this->seqNum = seqNum;
}

unsigned int EnquireMessage::getOwnerIndex() const
{
    return this->ownerIndex;
}

void EnquireMessage::setOwnerIndex(unsigned int ownerIndex)
{
    this->ownerIndex = ownerIndex;
}

L3Address& EnquireMessage::getSourceAddr()
{
    return this->sourceAddr;
}

void EnquireMessage::setSourceAddr(const L3Address& sourceAddr)
{
    this->sourceAddr = sourceAddr;
}

L3Address& EnquireMessage::getOwnerAddr()
{
    return this->ownerAddr;
}

void EnquireMessage::setOwnerAddr(const L3Address& ownerAddr)
{
    this->ownerAddr = ownerAddr;
}

L3Address& EnquireMessage::getDestAddr()
{
    return this->destAddr;
}

void EnquireMessage::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

::omnetpp::simtime_t EnquireMessage::getDestContactDuration() const
{
    return this->destContactDuration;
}

void EnquireMessage::setDestContactDuration(::omnetpp::simtime_t destContactDuration)
{
    this->destContactDuration = destContactDuration;
}

class EnquireMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EnquireMessageDescriptor();
    virtual ~EnquireMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EnquireMessageDescriptor);

EnquireMessageDescriptor::EnquireMessageDescriptor() : omnetpp::cClassDescriptor("inet::EnquireMessage", "inet::EPFControlPacket")
{
    propertynames = nullptr;
}

EnquireMessageDescriptor::~EnquireMessageDescriptor()
{
    delete[] propertynames;
}

bool EnquireMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EnquireMessage *>(obj)!=nullptr;
}

const char **EnquireMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EnquireMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EnquireMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int EnquireMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *EnquireMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "hostIndex",
        "destIndex",
        "seqNum",
        "ownerIndex",
        "sourceAddr",
        "ownerAddr",
        "destAddr",
        "destContactDuration",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int EnquireMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hostIndex")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIndex")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+3;
    if (fieldName[0]=='o' && strcmp(fieldName, "ownerIndex")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddr")==0) return base+5;
    if (fieldName[0]=='o' && strcmp(fieldName, "ownerAddr")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "destContactDuration")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EnquireMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "L3Address",
        "L3Address",
        "simtime_t",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **EnquireMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EnquireMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EnquireMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EnquireMessage *pp = (EnquireMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EnquireMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EnquireMessage *pp = (EnquireMessage *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHostIndex());
        case 2: return ulong2string(pp->getDestIndex());
        case 3: return ulong2string(pp->getSeqNum());
        case 4: return ulong2string(pp->getOwnerIndex());
        case 5: {std::stringstream out; out << pp->getSourceAddr(); return out.str();}
        case 6: {std::stringstream out; out << pp->getOwnerAddr(); return out.str();}
        case 7: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 8: return simtime2string(pp->getDestContactDuration());
        default: return "";
    }
}

bool EnquireMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EnquireMessage *pp = (EnquireMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHostIndex(string2ulong(value)); return true;
        case 2: pp->setDestIndex(string2ulong(value)); return true;
        case 3: pp->setSeqNum(string2ulong(value)); return true;
        case 4: pp->setOwnerIndex(string2ulong(value)); return true;
        case 8: pp->setDestContactDuration(string2simtime(value)); return true;
        default: return false;
    }
}

const char *EnquireMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(L3Address));
        case 6: return omnetpp::opp_typename(typeid(L3Address));
        case 7: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *EnquireMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EnquireMessage *pp = (EnquireMessage *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getSourceAddr()); break;
        case 6: return (void *)(&pp->getOwnerAddr()); break;
        case 7: return (void *)(&pp->getDestAddr()); break;
        default: return nullptr;
    }
}

Register_Class(EnquireResponse);

EnquireResponse::EnquireResponse(const char *name) : ::inet::EPFControlPacket(name)
{
    this->packetType = Response;
    this->hostIndex = 0;
    this->destIndex = 0;
    this->ownerIndex = 0;
    this->seqNum = 0;
    this->okToSend = false;
    this->destReached = false;
}

EnquireResponse::EnquireResponse(const EnquireResponse& other) : ::inet::EPFControlPacket(other)
{
    copy(other);
}

EnquireResponse::~EnquireResponse()
{
}

EnquireResponse& EnquireResponse::operator=(const EnquireResponse& other)
{
    if (this==&other) return *this;
    ::inet::EPFControlPacket::operator=(other);
    copy(other);
    return *this;
}

void EnquireResponse::copy(const EnquireResponse& other)
{
    this->packetType = other.packetType;
    this->hostIndex = other.hostIndex;
    this->destIndex = other.destIndex;
    this->ownerIndex = other.ownerIndex;
    this->seqNum = other.seqNum;
    this->sourceAddr = other.sourceAddr;
    this->ownerAddr = other.ownerAddr;
    this->respondTo = other.respondTo;
    this->destAddr = other.destAddr;
    this->okToSend = other.okToSend;
    this->destReached = other.destReached;
}

void EnquireResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EPFControlPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->hostIndex);
    doParsimPacking(b,this->destIndex);
    doParsimPacking(b,this->ownerIndex);
    doParsimPacking(b,this->seqNum);
    doParsimPacking(b,this->sourceAddr);
    doParsimPacking(b,this->ownerAddr);
    doParsimPacking(b,this->respondTo);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->okToSend);
    doParsimPacking(b,this->destReached);
}

void EnquireResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EPFControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->hostIndex);
    doParsimUnpacking(b,this->destIndex);
    doParsimUnpacking(b,this->ownerIndex);
    doParsimUnpacking(b,this->seqNum);
    doParsimUnpacking(b,this->sourceAddr);
    doParsimUnpacking(b,this->ownerAddr);
    doParsimUnpacking(b,this->respondTo);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->okToSend);
    doParsimUnpacking(b,this->destReached);
}

unsigned int EnquireResponse::getPacketType() const
{
    return this->packetType;
}

void EnquireResponse::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

unsigned int EnquireResponse::getHostIndex() const
{
    return this->hostIndex;
}

void EnquireResponse::setHostIndex(unsigned int hostIndex)
{
    this->hostIndex = hostIndex;
}

unsigned int EnquireResponse::getDestIndex() const
{
    return this->destIndex;
}

void EnquireResponse::setDestIndex(unsigned int destIndex)
{
    this->destIndex = destIndex;
}

unsigned int EnquireResponse::getOwnerIndex() const
{
    return this->ownerIndex;
}

void EnquireResponse::setOwnerIndex(unsigned int ownerIndex)
{
    this->ownerIndex = ownerIndex;
}

unsigned int EnquireResponse::getSeqNum() const
{
    return this->seqNum;
}

void EnquireResponse::setSeqNum(unsigned int seqNum)
{
    this->seqNum = seqNum;
}

L3Address& EnquireResponse::getSourceAddr()
{
    return this->sourceAddr;
}

void EnquireResponse::setSourceAddr(const L3Address& sourceAddr)
{
    this->sourceAddr = sourceAddr;
}

L3Address& EnquireResponse::getOwnerAddr()
{
    return this->ownerAddr;
}

void EnquireResponse::setOwnerAddr(const L3Address& ownerAddr)
{
    this->ownerAddr = ownerAddr;
}

L3Address& EnquireResponse::getRespondTo()
{
    return this->respondTo;
}

void EnquireResponse::setRespondTo(const L3Address& respondTo)
{
    this->respondTo = respondTo;
}

L3Address& EnquireResponse::getDestAddr()
{
    return this->destAddr;
}

void EnquireResponse::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

bool EnquireResponse::getOkToSend() const
{
    return this->okToSend;
}

void EnquireResponse::setOkToSend(bool okToSend)
{
    this->okToSend = okToSend;
}

bool EnquireResponse::getDestReached() const
{
    return this->destReached;
}

void EnquireResponse::setDestReached(bool destReached)
{
    this->destReached = destReached;
}

class EnquireResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EnquireResponseDescriptor();
    virtual ~EnquireResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(EnquireResponseDescriptor);

EnquireResponseDescriptor::EnquireResponseDescriptor() : omnetpp::cClassDescriptor("inet::EnquireResponse", "inet::EPFControlPacket")
{
    propertynames = nullptr;
}

EnquireResponseDescriptor::~EnquireResponseDescriptor()
{
    delete[] propertynames;
}

bool EnquireResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EnquireResponse *>(obj)!=nullptr;
}

const char **EnquireResponseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EnquireResponseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EnquireResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int EnquireResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *EnquireResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "hostIndex",
        "destIndex",
        "ownerIndex",
        "seqNum",
        "sourceAddr",
        "ownerAddr",
        "respondTo",
        "destAddr",
        "okToSend",
        "destReached",
    };
    return (field>=0 && field<11) ? fieldNames[field] : nullptr;
}

int EnquireResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hostIndex")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIndex")==0) return base+2;
    if (fieldName[0]=='o' && strcmp(fieldName, "ownerIndex")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddr")==0) return base+5;
    if (fieldName[0]=='o' && strcmp(fieldName, "ownerAddr")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "respondTo")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+8;
    if (fieldName[0]=='o' && strcmp(fieldName, "okToSend")==0) return base+9;
    if (fieldName[0]=='d' && strcmp(fieldName, "destReached")==0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EnquireResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "L3Address",
        "L3Address",
        "L3Address",
        "bool",
        "bool",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : nullptr;
}

const char **EnquireResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EnquireResponseDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EnquireResponseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EnquireResponse *pp = (EnquireResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string EnquireResponseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EnquireResponse *pp = (EnquireResponse *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHostIndex());
        case 2: return ulong2string(pp->getDestIndex());
        case 3: return ulong2string(pp->getOwnerIndex());
        case 4: return ulong2string(pp->getSeqNum());
        case 5: {std::stringstream out; out << pp->getSourceAddr(); return out.str();}
        case 6: {std::stringstream out; out << pp->getOwnerAddr(); return out.str();}
        case 7: {std::stringstream out; out << pp->getRespondTo(); return out.str();}
        case 8: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 9: return bool2string(pp->getOkToSend());
        case 10: return bool2string(pp->getDestReached());
        default: return "";
    }
}

bool EnquireResponseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EnquireResponse *pp = (EnquireResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHostIndex(string2ulong(value)); return true;
        case 2: pp->setDestIndex(string2ulong(value)); return true;
        case 3: pp->setOwnerIndex(string2ulong(value)); return true;
        case 4: pp->setSeqNum(string2ulong(value)); return true;
        case 9: pp->setOkToSend(string2bool(value)); return true;
        case 10: pp->setDestReached(string2bool(value)); return true;
        default: return false;
    }
}

const char *EnquireResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(L3Address));
        case 6: return omnetpp::opp_typename(typeid(L3Address));
        case 7: return omnetpp::opp_typename(typeid(L3Address));
        case 8: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *EnquireResponseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EnquireResponse *pp = (EnquireResponse *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getSourceAddr()); break;
        case 6: return (void *)(&pp->getOwnerAddr()); break;
        case 7: return (void *)(&pp->getRespondTo()); break;
        case 8: return (void *)(&pp->getDestAddr()); break;
        default: return nullptr;
    }
}

Register_Class(DataMessage);

DataMessage::DataMessage(const char *name) : ::inet::EPFControlPacket(name)
{
    this->packetType = Data;
    this->hostIndex = 0;
    this->destIndex = 0;
    this->ownerIndex = 0;
    this->seqNum = 0;
    for (unsigned int i=0; i<20; i++)
        this->data[i] = 0;
}

DataMessage::DataMessage(const DataMessage& other) : ::inet::EPFControlPacket(other)
{
    copy(other);
}

DataMessage::~DataMessage()
{
}

DataMessage& DataMessage::operator=(const DataMessage& other)
{
    if (this==&other) return *this;
    ::inet::EPFControlPacket::operator=(other);
    copy(other);
    return *this;
}

void DataMessage::copy(const DataMessage& other)
{
    this->packetType = other.packetType;
    this->hostIndex = other.hostIndex;
    this->destIndex = other.destIndex;
    this->ownerIndex = other.ownerIndex;
    this->seqNum = other.seqNum;
    this->sourceAddr = other.sourceAddr;
    this->destAddr = other.destAddr;
    this->respondTo = other.respondTo;
    this->ownerAddr = other.ownerAddr;
    for (unsigned int i=0; i<20; i++)
        this->data[i] = other.data[i];
}

void DataMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EPFControlPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->hostIndex);
    doParsimPacking(b,this->destIndex);
    doParsimPacking(b,this->ownerIndex);
    doParsimPacking(b,this->seqNum);
    doParsimPacking(b,this->sourceAddr);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->respondTo);
    doParsimPacking(b,this->ownerAddr);
    doParsimArrayPacking(b,this->data,20);
}

void DataMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EPFControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->hostIndex);
    doParsimUnpacking(b,this->destIndex);
    doParsimUnpacking(b,this->ownerIndex);
    doParsimUnpacking(b,this->seqNum);
    doParsimUnpacking(b,this->sourceAddr);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->respondTo);
    doParsimUnpacking(b,this->ownerAddr);
    doParsimArrayUnpacking(b,this->data,20);
}

unsigned int DataMessage::getPacketType() const
{
    return this->packetType;
}

void DataMessage::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

unsigned int DataMessage::getHostIndex() const
{
    return this->hostIndex;
}

void DataMessage::setHostIndex(unsigned int hostIndex)
{
    this->hostIndex = hostIndex;
}

unsigned int DataMessage::getDestIndex() const
{
    return this->destIndex;
}

void DataMessage::setDestIndex(unsigned int destIndex)
{
    this->destIndex = destIndex;
}

unsigned int DataMessage::getOwnerIndex() const
{
    return this->ownerIndex;
}

void DataMessage::setOwnerIndex(unsigned int ownerIndex)
{
    this->ownerIndex = ownerIndex;
}

unsigned int DataMessage::getSeqNum() const
{
    return this->seqNum;
}

void DataMessage::setSeqNum(unsigned int seqNum)
{
    this->seqNum = seqNum;
}

L3Address& DataMessage::getSourceAddr()
{
    return this->sourceAddr;
}

void DataMessage::setSourceAddr(const L3Address& sourceAddr)
{
    this->sourceAddr = sourceAddr;
}

L3Address& DataMessage::getDestAddr()
{
    return this->destAddr;
}

void DataMessage::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

L3Address& DataMessage::getRespondTo()
{
    return this->respondTo;
}

void DataMessage::setRespondTo(const L3Address& respondTo)
{
    this->respondTo = respondTo;
}

L3Address& DataMessage::getOwnerAddr()
{
    return this->ownerAddr;
}

void DataMessage::setOwnerAddr(const L3Address& ownerAddr)
{
    this->ownerAddr = ownerAddr;
}

unsigned int DataMessage::getDataArraySize() const
{
    return 20;
}

char DataMessage::getData(unsigned int k) const
{
    if (k>=20) throw omnetpp::cRuntimeError("Array of size 20 indexed by %lu", (unsigned long)k);
    return this->data[k];
}

void DataMessage::setData(unsigned int k, char data)
{
    if (k>=20) throw omnetpp::cRuntimeError("Array of size 20 indexed by %lu", (unsigned long)k);
    this->data[k] = data;
}

class DataMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    DataMessageDescriptor();
    virtual ~DataMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(DataMessageDescriptor);

DataMessageDescriptor::DataMessageDescriptor() : omnetpp::cClassDescriptor("inet::DataMessage", "inet::EPFControlPacket")
{
    propertynames = nullptr;
}

DataMessageDescriptor::~DataMessageDescriptor()
{
    delete[] propertynames;
}

bool DataMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DataMessage *>(obj)!=nullptr;
}

const char **DataMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DataMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DataMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int DataMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *DataMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "hostIndex",
        "destIndex",
        "ownerIndex",
        "seqNum",
        "sourceAddr",
        "destAddr",
        "respondTo",
        "ownerAddr",
        "data",
    };
    return (field>=0 && field<10) ? fieldNames[field] : nullptr;
}

int DataMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hostIndex")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIndex")==0) return base+2;
    if (fieldName[0]=='o' && strcmp(fieldName, "ownerIndex")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddr")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "respondTo")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "ownerAddr")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DataMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "L3Address",
        "L3Address",
        "L3Address",
        "char",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : nullptr;
}

const char **DataMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DataMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DataMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DataMessage *pp = (DataMessage *)object; (void)pp;
    switch (field) {
        case 9: return 20;
        default: return 0;
    }
}

std::string DataMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DataMessage *pp = (DataMessage *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHostIndex());
        case 2: return ulong2string(pp->getDestIndex());
        case 3: return ulong2string(pp->getOwnerIndex());
        case 4: return ulong2string(pp->getSeqNum());
        case 5: {std::stringstream out; out << pp->getSourceAddr(); return out.str();}
        case 6: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 7: {std::stringstream out; out << pp->getRespondTo(); return out.str();}
        case 8: {std::stringstream out; out << pp->getOwnerAddr(); return out.str();}
        case 9: return long2string(pp->getData(i));
        default: return "";
    }
}

bool DataMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DataMessage *pp = (DataMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHostIndex(string2ulong(value)); return true;
        case 2: pp->setDestIndex(string2ulong(value)); return true;
        case 3: pp->setOwnerIndex(string2ulong(value)); return true;
        case 4: pp->setSeqNum(string2ulong(value)); return true;
        case 9: pp->setData(i,string2long(value)); return true;
        default: return false;
    }
}

const char *DataMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(L3Address));
        case 6: return omnetpp::opp_typename(typeid(L3Address));
        case 7: return omnetpp::opp_typename(typeid(L3Address));
        case 8: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *DataMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DataMessage *pp = (DataMessage *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getSourceAddr()); break;
        case 6: return (void *)(&pp->getDestAddr()); break;
        case 7: return (void *)(&pp->getRespondTo()); break;
        case 8: return (void *)(&pp->getOwnerAddr()); break;
        default: return nullptr;
    }
}

} // namespace inet

