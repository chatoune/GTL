#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-0.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@gtlDataList' list                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlDataList : public cCollectionElement {
  public : GALGAS_gtlDataList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlDataList (const GALGAS_gtlData & in_data
                                           COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_gtlDataList::cCollectionElement_gtlDataList (const GALGAS_gtlData & in_data
                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_data) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlDataList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlDataList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlDataList (mObject.mAttribute_data COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlDataList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "data" ":" ;
  mObject.mAttribute_data.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlDataList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlDataList * operand = (cCollectionElement_gtlDataList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlDataList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList::GALGAS_gtlDataList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList::GALGAS_gtlDataList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlDataList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::constructor_listWithValue (const GALGAS_gtlData & inOperand0
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlDataList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlDataList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                    const GALGAS_gtlData & in_data
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlDataList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlDataList (in_data COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::addAssign_operation (const GALGAS_gtlData & inOperand0
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlDataList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::setter_insertAtIndex (const GALGAS_gtlData inOperand0,
                                               const GALGAS_uint inInsertionIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlDataList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::setter_removeAtIndex (GALGAS_gtlData & outOperand0,
                                               const GALGAS_uint inRemoveIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
      outOperand0 = p->mObject.mAttribute_data ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::setter_popFirst (GALGAS_gtlData & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mAttribute_data ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::setter_popLast (GALGAS_gtlData & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mAttribute_data ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::method_first (GALGAS_gtlData & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mAttribute_data ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::method_last (GALGAS_gtlData & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mAttribute_data ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::add_operation (const GALGAS_gtlDataList & inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlDataList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::plusAssign_operation (const GALGAS_gtlDataList inOperand,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlDataList::getter_dataAtIndex (const GALGAS_uint & inIndex,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  GALGAS_gtlData result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    result = p->mObject.mAttribute_data ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlDataList::cEnumerator_gtlDataList (const GALGAS_gtlDataList & inEnumeratedObject,
                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList_2D_element cEnumerator_gtlDataList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlDataList * p = (const cCollectionElement_gtlDataList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData cEnumerator_gtlDataList::current_data (LOCATION_ARGS) const {
  const cCollectionElement_gtlDataList * p = (const cCollectionElement_gtlDataList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
  return p->mObject.mAttribute_data ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlDataList type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDataList ("gtlDataList",
                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlDataList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDataList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlDataList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDataList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlDataList result ;
  const GALGAS_gtlDataList * p = (const GALGAS_gtlDataList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDataList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDataList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlVarMap::cMapElement_gtlVarMap (const GALGAS_lstring & inKey,
                                              const GALGAS_gtlData & in_value
                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlVarMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlVarMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlVarMap (mAttribute_lkey, mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlVarMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlVarMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlVarMap * operand = (cMapElement_gtlVarMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (operand->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap::GALGAS_gtlVarMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap::GALGAS_gtlVarMap (const GALGAS_gtlVarMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap & GALGAS_gtlVarMap::operator = (const GALGAS_gtlVarMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlVarMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlVarMap::constructor_mapWithMapToOverride (const GALGAS_gtlVarMap & inMapToOverride
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlVarMap::getter_overriddenMap (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::addAssign_operation (const GALGAS_lstring & inKey,
                                            const GALGAS_gtlData & inArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlVarMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::setter_put (GALGAS_lstring inKey,
                                   GALGAS_gtlData inArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a variable or field named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlVarMap_get = "there is no variable or field named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::method_get (GALGAS_lstring inKey,
                                   GALGAS_gtlData & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_gtlVarMap_get
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlVarMap_getResult = "function did not return a value in '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::method_getResult (GALGAS_lstring inKey,
                                         GALGAS_gtlData & outArgument0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_gtlVarMap_getResult
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::setter_del (GALGAS_lstring inKey,
                                   GALGAS_gtlData & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "there is no variable or field named '%K' to delete" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_gtlVarMap * p = (cMapElement_gtlVarMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlVarMap::getter_valueForKey (const GALGAS_string & inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) attributes ;
  GALGAS_gtlData result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::setter_setValueForKey (GALGAS_gtlData inAttributeValue,
                                              GALGAS_string inKey,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlVarMap * p = (cMapElement_gtlVarMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    p->mAttribute_value = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlVarMap * GALGAS_gtlVarMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                             const GALGAS_string & inKey
                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * result = (cMapElement_gtlVarMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlVarMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlVarMap::cEnumerator_gtlVarMap (const GALGAS_gtlVarMap & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap_2D_element cEnumerator_gtlVarMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlVarMap) ;
  return GALGAS_gtlVarMap_2D_element (p->mAttribute_lkey, p->mAttribute_value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlVarMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData cEnumerator_gtlVarMap::current_value (LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlVarMap) ;
  return p->mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlVarMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarMap ("gtlVarMap",
                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlVarMap::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  const GALGAS_gtlVarMap * p = (const GALGAS_gtlVarMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlExpressionMap::cMapElement_gtlExpressionMap (const GALGAS_lstring & inKey,
                                                            const GALGAS_gtlExpression & in_expression
                                                            COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_expression (in_expression) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlExpressionMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_expression.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlExpressionMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlExpressionMap (mAttribute_lkey, mAttribute_expression COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlExpressionMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "expression" ":" ;
  mAttribute_expression.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlExpressionMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlExpressionMap * operand = (cMapElement_gtlExpressionMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_expression.objectCompare (operand->mAttribute_expression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap::GALGAS_gtlExpressionMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap::GALGAS_gtlExpressionMap (const GALGAS_gtlExpressionMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap & GALGAS_gtlExpressionMap::operator = (const GALGAS_gtlExpressionMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::constructor_mapWithMapToOverride (const GALGAS_gtlExpressionMap & inMapToOverride
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                   const GALGAS_gtlExpression & inArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlExpressionMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlExpressionMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::setter_put (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlExpressionMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a field named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlExpressionMap_get = "there is no field named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::method_get (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_gtlExpressionMap_get
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    outArgument0 = p->mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::setter_del (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "there is no field named '%K' to delete" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_gtlExpressionMap * p = (cMapElement_gtlExpressionMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    outArgument0 = p->mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExpressionMap::getter_expressionForKey (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) attributes ;
  GALGAS_gtlExpression result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    result = p->mAttribute_expression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::setter_setExpressionForKey (GALGAS_gtlExpression inAttributeValue,
                                                          GALGAS_string inKey,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlExpressionMap * p = (cMapElement_gtlExpressionMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    p->mAttribute_expression = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlExpressionMap * GALGAS_gtlExpressionMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * result = (cMapElement_gtlExpressionMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlExpressionMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlExpressionMap::cEnumerator_gtlExpressionMap (const GALGAS_gtlExpressionMap & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap_2D_element cEnumerator_gtlExpressionMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
  return GALGAS_gtlExpressionMap_2D_element (p->mAttribute_lkey, p->mAttribute_expression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlExpressionMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cEnumerator_gtlExpressionMap::current_expression (LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
  return p->mAttribute_expression ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlExpressionMap type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionMap ("gtlExpressionMap",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExpressionMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExpressionMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  const GALGAS_gtlExpressionMap * p = (const GALGAS_gtlExpressionMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpressionMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpressionMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Class for element of '@gtlInstructionList' list                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlInstructionList : public cCollectionElement {
  public : GALGAS_gtlInstructionList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlInstructionList (const GALGAS_gtlInstruction & in_instruction
                                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_gtlInstructionList::cCollectionElement_gtlInstructionList (const GALGAS_gtlInstruction & in_instruction
                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_instruction) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlInstructionList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlInstructionList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlInstructionList (mObject.mAttribute_instruction COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlInstructionList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "instruction" ":" ;
  mObject.mAttribute_instruction.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlInstructionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlInstructionList * operand = (cCollectionElement_gtlInstructionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlInstructionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList::GALGAS_gtlInstructionList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList::GALGAS_gtlInstructionList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlInstructionList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::constructor_listWithValue (const GALGAS_gtlInstruction & inOperand0
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlInstructionList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                           const GALGAS_gtlInstruction & in_instruction
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlInstructionList (in_instruction COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::addAssign_operation (const GALGAS_gtlInstruction & inOperand0
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlInstructionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_insertAtIndex (const GALGAS_gtlInstruction inOperand0,
                                                      const GALGAS_uint inInsertionIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlInstructionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_removeAtIndex (GALGAS_gtlInstruction & outOperand0,
                                                      const GALGAS_uint inRemoveIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
      outOperand0 = p->mObject.mAttribute_instruction ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_popFirst (GALGAS_gtlInstruction & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mAttribute_instruction ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_popLast (GALGAS_gtlInstruction & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mAttribute_instruction ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::method_first (GALGAS_gtlInstruction & outOperand0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mAttribute_instruction ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::method_last (GALGAS_gtlInstruction & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mAttribute_instruction ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::add_operation (const GALGAS_gtlInstructionList & inOperand,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::plusAssign_operation (const GALGAS_gtlInstructionList inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction GALGAS_gtlInstructionList::getter_instructionAtIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  GALGAS_gtlInstruction result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    result = p->mObject.mAttribute_instruction ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlInstructionList::cEnumerator_gtlInstructionList (const GALGAS_gtlInstructionList & inEnumeratedObject,
                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList_2D_element cEnumerator_gtlInstructionList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionList * p = (const cCollectionElement_gtlInstructionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction cEnumerator_gtlInstructionList::current_instruction (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionList * p = (const cCollectionElement_gtlInstructionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
  return p->mObject.mAttribute_instruction ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlInstructionList type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionList ("gtlInstructionList",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlInstructionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlInstructionList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionList result ;
  const GALGAS_gtlInstructionList * p = (const GALGAS_gtlInstructionList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInstructionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlTemplateMap::cMapElement_gtlTemplateMap (const GALGAS_lstring & inKey,
                                                        const GALGAS_gtlTemplate & in_aTemplate
                                                        COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_aTemplate (in_aTemplate) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlTemplateMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_aTemplate.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlTemplateMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlTemplateMap (mAttribute_lkey, mAttribute_aTemplate COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlTemplateMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "aTemplate" ":" ;
  mAttribute_aTemplate.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlTemplateMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlTemplateMap * operand = (cMapElement_gtlTemplateMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_aTemplate.objectCompare (operand->mAttribute_aTemplate) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap::GALGAS_gtlTemplateMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap::GALGAS_gtlTemplateMap (const GALGAS_gtlTemplateMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap & GALGAS_gtlTemplateMap::operator = (const GALGAS_gtlTemplateMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::constructor_mapWithMapToOverride (const GALGAS_gtlTemplateMap & inMapToOverride
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTemplateMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                 const GALGAS_gtlTemplate & inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlTemplateMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlTemplateMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap::setter_put (GALGAS_lstring inKey,
                                        GALGAS_gtlTemplate inArgument0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlTemplateMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a template at path '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlTemplateMap_get = "there is no template at path '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap::method_get (GALGAS_lstring inKey,
                                        GALGAS_gtlTemplate & outArgument0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) performSearch (inKey,
                                                                                               inCompiler,
                                                                                               kSearchErrorMessage_gtlTemplateMap_get
                                                                                               COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    outArgument0 = p->mAttribute_aTemplate ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate GALGAS_gtlTemplateMap::getter_aTemplateForKey (const GALGAS_string & inKey,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) attributes ;
  GALGAS_gtlTemplate result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    result = p->mAttribute_aTemplate ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap::setter_setATemplateForKey (GALGAS_gtlTemplate inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlTemplateMap * p = (cMapElement_gtlTemplateMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    p->mAttribute_aTemplate = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlTemplateMap * GALGAS_gtlTemplateMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * result = (cMapElement_gtlTemplateMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlTemplateMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlTemplateMap::cEnumerator_gtlTemplateMap (const GALGAS_gtlTemplateMap & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap_2D_element cEnumerator_gtlTemplateMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
  return GALGAS_gtlTemplateMap_2D_element (p->mAttribute_lkey, p->mAttribute_aTemplate) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlTemplateMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate cEnumerator_gtlTemplateMap::current_aTemplate (LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
  return p->mAttribute_aTemplate ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @gtlTemplateMap type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateMap ("gtlTemplateMap",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTemplateMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTemplateMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  const GALGAS_gtlTemplateMap * p = (const GALGAS_gtlTemplateMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTemplateMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplateMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlFuncMap::cMapElement_gtlFuncMap (const GALGAS_lstring & inKey,
                                                const GALGAS_gtlFunction & in_function
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_function (in_function) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlFuncMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_function.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlFuncMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlFuncMap (mAttribute_lkey, mAttribute_function COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlFuncMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "function" ":" ;
  mAttribute_function.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlFuncMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlFuncMap * operand = (cMapElement_gtlFuncMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_function.objectCompare (operand->mAttribute_function) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap::GALGAS_gtlFuncMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap::GALGAS_gtlFuncMap (const GALGAS_gtlFuncMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap & GALGAS_gtlFuncMap::operator = (const GALGAS_gtlFuncMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::constructor_mapWithMapToOverride (const GALGAS_gtlFuncMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_gtlFuncMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_gtlFunction & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlFuncMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlFuncMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_gtlFunction inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlFuncMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a function named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlFuncMap_get = "there is no function named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_gtlFunction & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_gtlFuncMap_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    outArgument0 = p->mAttribute_function ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction GALGAS_gtlFuncMap::getter_functionForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) attributes ;
  GALGAS_gtlFunction result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    result = p->mAttribute_function ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap::setter_setFunctionForKey (GALGAS_gtlFunction inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlFuncMap * p = (cMapElement_gtlFuncMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    p->mAttribute_function = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlFuncMap * GALGAS_gtlFuncMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * result = (cMapElement_gtlFuncMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlFuncMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlFuncMap::cEnumerator_gtlFuncMap (const GALGAS_gtlFuncMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap_2D_element cEnumerator_gtlFuncMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
  return GALGAS_gtlFuncMap_2D_element (p->mAttribute_lkey, p->mAttribute_function) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlFuncMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction cEnumerator_gtlFuncMap::current_function (LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
  return p->mAttribute_function ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlFuncMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFuncMap ("gtlFuncMap",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlFuncMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFuncMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlFuncMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFuncMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  const GALGAS_gtlFuncMap * p = (const GALGAS_gtlFuncMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlFuncMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlFuncMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlGetterMap::cMapElement_gtlGetterMap (const GALGAS_lstring & inKey,
                                                    const GALGAS_gtlGetter & in_theGetter
                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_theGetter (in_theGetter) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlGetterMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_theGetter.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlGetterMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlGetterMap (mAttribute_lkey, mAttribute_theGetter COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlGetterMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "theGetter" ":" ;
  mAttribute_theGetter.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlGetterMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlGetterMap * operand = (cMapElement_gtlGetterMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_theGetter.objectCompare (operand->mAttribute_theGetter) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap::GALGAS_gtlGetterMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap::GALGAS_gtlGetterMap (const GALGAS_gtlGetterMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap & GALGAS_gtlGetterMap::operator = (const GALGAS_gtlGetterMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::constructor_mapWithMapToOverride (const GALGAS_gtlGetterMap & inMapToOverride
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::getter_overriddenMap (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_gtlGetterMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap::addAssign_operation (const GALGAS_lstring & inKey,
                                               const GALGAS_gtlGetter & inArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlGetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlGetterMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap::setter_put (GALGAS_lstring inKey,
                                      GALGAS_gtlGetter inArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlGetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a getter named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlGetterMap_get = "there is no getter named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap::method_get (GALGAS_lstring inKey,
                                      GALGAS_gtlGetter & outArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_gtlGetterMap_get
                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    outArgument0 = p->mAttribute_theGetter ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter GALGAS_gtlGetterMap::getter_theGetterForKey (const GALGAS_string & inKey,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) attributes ;
  GALGAS_gtlGetter result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    result = p->mAttribute_theGetter ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap::setter_setTheGetterForKey (GALGAS_gtlGetter inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlGetterMap * p = (cMapElement_gtlGetterMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    p->mAttribute_theGetter = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlGetterMap * GALGAS_gtlGetterMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                   const GALGAS_string & inKey
                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * result = (cMapElement_gtlGetterMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlGetterMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlGetterMap::cEnumerator_gtlGetterMap (const GALGAS_gtlGetterMap & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap_2D_element cEnumerator_gtlGetterMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
  return GALGAS_gtlGetterMap_2D_element (p->mAttribute_lkey, p->mAttribute_theGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlGetterMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter cEnumerator_gtlGetterMap::current_theGetter (LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
  return p->mAttribute_theGetter ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @gtlGetterMap type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetterMap ("gtlGetterMap",
                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlGetterMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlGetterMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetterMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  const GALGAS_gtlGetterMap * p = (const GALGAS_gtlGetterMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGetterMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetterMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlSetterMap::cMapElement_gtlSetterMap (const GALGAS_lstring & inKey,
                                                    const GALGAS_gtlSetter & in_theSetter
                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_theSetter (in_theSetter) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlSetterMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_theSetter.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlSetterMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlSetterMap (mAttribute_lkey, mAttribute_theSetter COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlSetterMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "theSetter" ":" ;
  mAttribute_theSetter.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlSetterMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlSetterMap * operand = (cMapElement_gtlSetterMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_theSetter.objectCompare (operand->mAttribute_theSetter) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap::GALGAS_gtlSetterMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap::GALGAS_gtlSetterMap (const GALGAS_gtlSetterMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap & GALGAS_gtlSetterMap::operator = (const GALGAS_gtlSetterMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::constructor_mapWithMapToOverride (const GALGAS_gtlSetterMap & inMapToOverride
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::getter_overriddenMap (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_gtlSetterMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap::addAssign_operation (const GALGAS_lstring & inKey,
                                               const GALGAS_gtlSetter & inArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlSetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlSetterMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap::setter_put (GALGAS_lstring inKey,
                                      GALGAS_gtlSetter inArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlSetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a setter named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlSetterMap_get = "there is no setter named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap::method_get (GALGAS_lstring inKey,
                                      GALGAS_gtlSetter & outArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_gtlSetterMap_get
                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    outArgument0 = p->mAttribute_theSetter ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter GALGAS_gtlSetterMap::getter_theSetterForKey (const GALGAS_string & inKey,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) attributes ;
  GALGAS_gtlSetter result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    result = p->mAttribute_theSetter ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap::setter_setTheSetterForKey (GALGAS_gtlSetter inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlSetterMap * p = (cMapElement_gtlSetterMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    p->mAttribute_theSetter = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlSetterMap * GALGAS_gtlSetterMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                   const GALGAS_string & inKey
                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * result = (cMapElement_gtlSetterMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlSetterMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlSetterMap::cEnumerator_gtlSetterMap (const GALGAS_gtlSetterMap & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap_2D_element cEnumerator_gtlSetterMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
  return GALGAS_gtlSetterMap_2D_element (p->mAttribute_lkey, p->mAttribute_theSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlSetterMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter cEnumerator_gtlSetterMap::current_theSetter (LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
  return p->mAttribute_theSetter ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @gtlSetterMap type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSetterMap ("gtlSetterMap",
                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSetterMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSetterMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSetterMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  const GALGAS_gtlSetterMap * p = (const GALGAS_gtlSetterMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSetterMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSetterMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Class for element of '@gtlTypedArgumentList' list                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlTypedArgumentList : public cCollectionElement {
  public : GALGAS_gtlTypedArgumentList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlTypedArgumentList (const GALGAS_type & in_type
                                                    COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_gtlTypedArgumentList::cCollectionElement_gtlTypedArgumentList (const GALGAS_type & in_type
                                                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_type) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlTypedArgumentList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlTypedArgumentList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlTypedArgumentList (mObject.mAttribute_type COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlTypedArgumentList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mObject.mAttribute_type.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlTypedArgumentList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlTypedArgumentList * operand = (cCollectionElement_gtlTypedArgumentList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlTypedArgumentList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList::GALGAS_gtlTypedArgumentList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList::GALGAS_gtlTypedArgumentList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::constructor_listWithValue (const GALGAS_type & inOperand0
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlTypedArgumentList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                             const GALGAS_type & in_type
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlTypedArgumentList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlTypedArgumentList (in_type COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::addAssign_operation (const GALGAS_type & inOperand0
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlTypedArgumentList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::setter_insertAtIndex (const GALGAS_type inOperand0,
                                                        const GALGAS_uint inInsertionIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlTypedArgumentList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::setter_removeAtIndex (GALGAS_type & outOperand0,
                                                        const GALGAS_uint inRemoveIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
      outOperand0 = p->mObject.mAttribute_type ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::setter_popFirst (GALGAS_type & outOperand0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::setter_popLast (GALGAS_type & outOperand0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::method_first (GALGAS_type & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::method_last (GALGAS_type & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::add_operation (const GALGAS_gtlTypedArgumentList & inOperand,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::plusAssign_operation (const GALGAS_gtlTypedArgumentList inOperand,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlTypedArgumentList::getter_typeAtIndex (const GALGAS_uint & inIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  GALGAS_type result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    result = p->mObject.mAttribute_type ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlTypedArgumentList::cEnumerator_gtlTypedArgumentList (const GALGAS_gtlTypedArgumentList & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList_2D_element cEnumerator_gtlTypedArgumentList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlTypedArgumentList * p = (const cCollectionElement_gtlTypedArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type cEnumerator_gtlTypedArgumentList::current_type (LOCATION_ARGS) const {
  const cCollectionElement_gtlTypedArgumentList * p = (const cCollectionElement_gtlTypedArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
  return p->mObject.mAttribute_type ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlTypedArgumentList type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTypedArgumentList ("gtlTypedArgumentList",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTypedArgumentList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypedArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTypedArgumentList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTypedArgumentList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result ;
  const GALGAS_gtlTypedArgumentList * p = (const GALGAS_gtlTypedArgumentList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTypedArgumentList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTypedArgumentList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Class for element of '@list' list                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_list : public cCollectionElement {
  public : GALGAS_list_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_list (const GALGAS_gtlData & in_value
                                    COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_list::cCollectionElement_list (const GALGAS_gtlData & in_value
                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_list::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_list::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_list (mObject.mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_list::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_list::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_list * operand = (cCollectionElement_list *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_list) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list::GALGAS_list (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list::GALGAS_list (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_list result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::constructor_listWithValue (const GALGAS_gtlData & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_list result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_list::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                             const GALGAS_gtlData & in_value
                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_list * p = NULL ;
  macroMyNew (p, cCollectionElement_list (in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::addAssign_operation (const GALGAS_gtlData & inOperand0
                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_insertAtIndex (const GALGAS_gtlData inOperand0,
                                        const GALGAS_uint inInsertionIndex,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_removeAtIndex (GALGAS_gtlData & outOperand0,
                                        const GALGAS_uint inRemoveIndex,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_list) ;
      outOperand0 = p->mObject.mAttribute_value ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_popFirst (GALGAS_gtlData & outOperand0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_popLast (GALGAS_gtlData & outOperand0,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::method_first (GALGAS_gtlData & outOperand0,
                                C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::method_last (GALGAS_gtlData & outOperand0,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::add_operation (const GALGAS_list & inOperand,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_list result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::getter_subListWithRange (const GALGAS_range & inRange,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::plusAssign_operation (const GALGAS_list inOperand,
                                        C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_setValueAtIndex (GALGAS_gtlData inOperand,
                                              GALGAS_uint inIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_list * p = (cCollectionElement_list *) objectPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_list) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mAttribute_value = inOperand ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_list::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  GALGAS_gtlData result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_list) ;
    result = p->mObject.mAttribute_value ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_list::cEnumerator_list (const GALGAS_list & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list_2D_element cEnumerator_list::current (LOCATION_ARGS) const {
  const cCollectionElement_list * p = (const cCollectionElement_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_list) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData cEnumerator_list::current_value (LOCATION_ARGS) const {
  const cCollectionElement_list * p = (const cCollectionElement_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_list) ;
  return p->mObject.mAttribute_value ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                     @list type                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_list ("list",
                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_list::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_list ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_list::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_list (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_list result ;
  const GALGAS_list * p = (const GALGAS_list *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_list *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("list", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@gtlVarPath' list                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlVarPath : public cCollectionElement {
  public : GALGAS_gtlVarPath_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlVarPath (const GALGAS_gtlVarItem & in_item
                                          COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_gtlVarPath::cCollectionElement_gtlVarPath (const GALGAS_gtlVarItem & in_item
                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_item) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlVarPath::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlVarPath::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlVarPath (mObject.mAttribute_item COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlVarPath::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "item" ":" ;
  mObject.mAttribute_item.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlVarPath::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlVarPath * operand = (cCollectionElement_gtlVarPath *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlVarPath) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath::GALGAS_gtlVarPath (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath::GALGAS_gtlVarPath (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlVarPath result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::constructor_listWithValue (const GALGAS_gtlVarItem & inOperand0
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarPath result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlVarPath::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                   const GALGAS_gtlVarItem & in_item
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlVarPath * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlVarPath (in_item COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::addAssign_operation (const GALGAS_gtlVarItem & inOperand0
                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlVarPath (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::setter_insertAtIndex (const GALGAS_gtlVarItem inOperand0,
                                              const GALGAS_uint inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlVarPath (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::setter_removeAtIndex (GALGAS_gtlVarItem & outOperand0,
                                              const GALGAS_uint inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
      outOperand0 = p->mObject.mAttribute_item ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::setter_popFirst (GALGAS_gtlVarItem & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::setter_popLast (GALGAS_gtlVarItem & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::method_first (GALGAS_gtlVarItem & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::method_last (GALGAS_gtlVarItem & outOperand0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::add_operation (const GALGAS_gtlVarPath & inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListWithRange (const GALGAS_range & inRange,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::plusAssign_operation (const GALGAS_gtlVarPath inOperand,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItem GALGAS_gtlVarPath::getter_itemAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  GALGAS_gtlVarItem result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    result = p->mObject.mAttribute_item ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlVarPath::cEnumerator_gtlVarPath (const GALGAS_gtlVarPath & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath_2D_element cEnumerator_gtlVarPath::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlVarPath * p = (const cCollectionElement_gtlVarPath *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItem cEnumerator_gtlVarPath::current_item (LOCATION_ARGS) const {
  const cCollectionElement_gtlVarPath * p = (const cCollectionElement_gtlVarPath *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
  return p->mObject.mAttribute_item ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlVarPath type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarPath ("gtlVarPath",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarPath::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarPath ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarPath::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarPath (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarPath result ;
  const GALGAS_gtlVarPath * p = (const GALGAS_gtlVarPath *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarPath *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarPath", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Class for element of '@gtlExpressionList' list                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlExpressionList : public cCollectionElement {
  public : GALGAS_gtlExpressionList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlExpressionList (const GALGAS_gtlExpression & in_expression
                                                 COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_gtlExpressionList::cCollectionElement_gtlExpressionList (const GALGAS_gtlExpression & in_expression
                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_expression) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlExpressionList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlExpressionList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlExpressionList (mObject.mAttribute_expression COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlExpressionList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "expression" ":" ;
  mObject.mAttribute_expression.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlExpressionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlExpressionList * operand = (cCollectionElement_gtlExpressionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlExpressionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList::GALGAS_gtlExpressionList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList::GALGAS_gtlExpressionList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlExpressionList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::constructor_listWithValue (const GALGAS_gtlExpression & inOperand0
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlExpressionList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                          const GALGAS_gtlExpression & in_expression
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlExpressionList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlExpressionList (in_expression COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::addAssign_operation (const GALGAS_gtlExpression & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlExpressionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::setter_insertAtIndex (const GALGAS_gtlExpression inOperand0,
                                                     const GALGAS_uint inInsertionIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlExpressionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::setter_removeAtIndex (GALGAS_gtlExpression & outOperand0,
                                                     const GALGAS_uint inRemoveIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
      outOperand0 = p->mObject.mAttribute_expression ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::setter_popFirst (GALGAS_gtlExpression & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::setter_popLast (GALGAS_gtlExpression & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::method_first (GALGAS_gtlExpression & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::method_last (GALGAS_gtlExpression & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::add_operation (const GALGAS_gtlExpressionList & inOperand,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::plusAssign_operation (const GALGAS_gtlExpressionList inOperand,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExpressionList::getter_expressionAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  GALGAS_gtlExpression result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    result = p->mObject.mAttribute_expression ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlExpressionList::cEnumerator_gtlExpressionList (const GALGAS_gtlExpressionList & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList_2D_element cEnumerator_gtlExpressionList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlExpressionList * p = (const cCollectionElement_gtlExpressionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cEnumerator_gtlExpressionList::current_expression (LOCATION_ARGS) const {
  const cCollectionElement_gtlExpressionList * p = (const cCollectionElement_gtlExpressionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
  return p->mObject.mAttribute_expression ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlExpressionList type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionList ("gtlExpressionList",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExpressionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExpressionList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionList result ;
  const GALGAS_gtlExpressionList * p = (const GALGAS_gtlExpressionList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpressionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpressionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Class for element of '@gtlThenElsifStatementList' list                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlThenElsifStatementList : public cCollectionElement {
  public : GALGAS_gtlThenElsifStatementList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlThenElsifStatementList (const GALGAS_gtlExpression & in_condition,
                                                         const GALGAS_gtlInstructionList & in_instructionList
                                                         COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_gtlThenElsifStatementList::cCollectionElement_gtlThenElsifStatementList (const GALGAS_gtlExpression & in_condition,
                                                                                            const GALGAS_gtlInstructionList & in_instructionList
                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_condition, in_instructionList) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlThenElsifStatementList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlThenElsifStatementList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlThenElsifStatementList (mObject.mAttribute_condition, mObject.mAttribute_instructionList COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlThenElsifStatementList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "condition" ":" ;
  mObject.mAttribute_condition.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "instructionList" ":" ;
  mObject.mAttribute_instructionList.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlThenElsifStatementList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlThenElsifStatementList * operand = (cCollectionElement_gtlThenElsifStatementList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlThenElsifStatementList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList::GALGAS_gtlThenElsifStatementList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList::GALGAS_gtlThenElsifStatementList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::constructor_listWithValue (const GALGAS_gtlExpression & inOperand0,
                                                                                              const GALGAS_gtlInstructionList & inOperand1
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlThenElsifStatementList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                  const GALGAS_gtlExpression & in_condition,
                                                                  const GALGAS_gtlInstructionList & in_instructionList
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlThenElsifStatementList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (in_condition,
                                                               in_instructionList COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::addAssign_operation (const GALGAS_gtlExpression & inOperand0,
                                                            const GALGAS_gtlInstructionList & inOperand1
                                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::setter_insertAtIndex (const GALGAS_gtlExpression inOperand0,
                                                             const GALGAS_gtlInstructionList inOperand1,
                                                             const GALGAS_uint inInsertionIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::setter_removeAtIndex (GALGAS_gtlExpression & outOperand0,
                                                             GALGAS_gtlInstructionList & outOperand1,
                                                             const GALGAS_uint inRemoveIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
      outOperand0 = p->mObject.mAttribute_condition ;
      outOperand1 = p->mObject.mAttribute_instructionList ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::setter_popFirst (GALGAS_gtlExpression & outOperand0,
                                                        GALGAS_gtlInstructionList & outOperand1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mAttribute_condition ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::setter_popLast (GALGAS_gtlExpression & outOperand0,
                                                       GALGAS_gtlInstructionList & outOperand1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mAttribute_condition ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::method_first (GALGAS_gtlExpression & outOperand0,
                                                     GALGAS_gtlInstructionList & outOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mAttribute_condition ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::method_last (GALGAS_gtlExpression & outOperand0,
                                                    GALGAS_gtlInstructionList & outOperand1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mAttribute_condition ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::add_operation (const GALGAS_gtlThenElsifStatementList & inOperand,
                                                                                  C_Compiler * /* inCompiler */
                                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::plusAssign_operation (const GALGAS_gtlThenElsifStatementList inOperand,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlThenElsifStatementList::getter_conditionAtIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  GALGAS_gtlExpression result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    result = p->mObject.mAttribute_condition ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlThenElsifStatementList::getter_instructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  GALGAS_gtlInstructionList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    result = p->mObject.mAttribute_instructionList ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlThenElsifStatementList::cEnumerator_gtlThenElsifStatementList (const GALGAS_gtlThenElsifStatementList & inEnumeratedObject,
                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList_2D_element cEnumerator_gtlThenElsifStatementList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cEnumerator_gtlThenElsifStatementList::current_condition (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject.mAttribute_condition ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cEnumerator_gtlThenElsifStatementList::current_instructionList (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject.mAttribute_instructionList ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlThenElsifStatementList type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlThenElsifStatementList ("gtlThenElsifStatementList",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlThenElsifStatementList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlThenElsifStatementList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlThenElsifStatementList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlThenElsifStatementList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList result ;
  const GALGAS_gtlThenElsifStatementList * p = (const GALGAS_gtlThenElsifStatementList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlThenElsifStatementList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlThenElsifStatementList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@sortingKeyList' list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_sortingKeyList : public cCollectionElement {
  public : GALGAS_sortingKeyList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_sortingKeyList (const GALGAS_lstring & in_key,
                                              const GALGAS_lsint & in_order
                                              COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_sortingKeyList::cCollectionElement_sortingKeyList (const GALGAS_lstring & in_key,
                                                                      const GALGAS_lsint & in_order
                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_key, in_order) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_sortingKeyList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_sortingKeyList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_sortingKeyList (mObject.mAttribute_key, mObject.mAttribute_order COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_sortingKeyList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "key" ":" ;
  mObject.mAttribute_key.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "order" ":" ;
  mObject.mAttribute_order.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_sortingKeyList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_sortingKeyList * operand = (cCollectionElement_sortingKeyList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_sortingKeyList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList::GALGAS_sortingKeyList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList::GALGAS_sortingKeyList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_sortingKeyList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_lsint & inOperand1
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sortingKeyList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_sortingKeyList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                       const GALGAS_lstring & in_key,
                                                       const GALGAS_lsint & in_order
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_sortingKeyList * p = NULL ;
  macroMyNew (p, cCollectionElement_sortingKeyList (in_key,
                                                    in_order COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                 const GALGAS_lsint & inOperand1
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sortingKeyList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                  const GALGAS_lsint inOperand1,
                                                  const GALGAS_uint inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sortingKeyList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                  GALGAS_lsint & outOperand1,
                                                  const GALGAS_uint inRemoveIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
      outOperand0 = p->mObject.mAttribute_key ;
      outOperand1 = p->mObject.mAttribute_order ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::setter_popFirst (GALGAS_lstring & outOperand0,
                                             GALGAS_lsint & outOperand1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mAttribute_key ;
    outOperand1 = p->mObject.mAttribute_order ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::setter_popLast (GALGAS_lstring & outOperand0,
                                            GALGAS_lsint & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mAttribute_key ;
    outOperand1 = p->mObject.mAttribute_order ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::method_first (GALGAS_lstring & outOperand0,
                                          GALGAS_lsint & outOperand1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mAttribute_key ;
    outOperand1 = p->mObject.mAttribute_order ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::method_last (GALGAS_lstring & outOperand0,
                                         GALGAS_lsint & outOperand1,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mAttribute_key ;
    outOperand1 = p->mObject.mAttribute_order ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::add_operation (const GALGAS_sortingKeyList & inOperand,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::plusAssign_operation (const GALGAS_sortingKeyList inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_sortingKeyList::getter_keyAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    result = p->mObject.mAttribute_key ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lsint GALGAS_sortingKeyList::getter_orderAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  GALGAS_lsint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    result = p->mObject.mAttribute_order ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_sortingKeyList::cEnumerator_sortingKeyList (const GALGAS_sortingKeyList & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList_2D_element cEnumerator_sortingKeyList::current (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_sortingKeyList::current_key (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject.mAttribute_key ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lsint cEnumerator_sortingKeyList::current_order (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject.mAttribute_order ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @sortingKeyList type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sortingKeyList ("sortingKeyList",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sortingKeyList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sortingKeyList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sortingKeyList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sortingKeyList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sortingKeyList result ;
  const GALGAS_sortingKeyList * p = (const GALGAS_sortingKeyList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sortingKeyList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sortingKeyList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@gtlArgumentList' list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlArgumentList : public cCollectionElement {
  public : GALGAS_gtlArgumentList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlArgumentList (const GALGAS_bool & in_typed,
                                               const GALGAS_type & in_type,
                                               const GALGAS_lstring & in_name
                                               COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_gtlArgumentList::cCollectionElement_gtlArgumentList (const GALGAS_bool & in_typed,
                                                                        const GALGAS_type & in_type,
                                                                        const GALGAS_lstring & in_name
                                                                        COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_typed, in_type, in_name) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlArgumentList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlArgumentList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlArgumentList (mObject.mAttribute_typed, mObject.mAttribute_type, mObject.mAttribute_name COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlArgumentList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "typed" ":" ;
  mObject.mAttribute_typed.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mObject.mAttribute_type.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "name" ":" ;
  mObject.mAttribute_name.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlArgumentList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlArgumentList * operand = (cCollectionElement_gtlArgumentList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlArgumentList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList::GALGAS_gtlArgumentList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList::GALGAS_gtlArgumentList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlArgumentList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::constructor_listWithValue (const GALGAS_bool & inOperand0,
                                                                          const GALGAS_type & inOperand1,
                                                                          const GALGAS_lstring & inOperand2
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlArgumentList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlArgumentList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                        const GALGAS_bool & in_typed,
                                                        const GALGAS_type & in_type,
                                                        const GALGAS_lstring & in_name
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlArgumentList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlArgumentList (in_typed,
                                                     in_type,
                                                     in_name COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::addAssign_operation (const GALGAS_bool & inOperand0,
                                                  const GALGAS_type & inOperand1,
                                                  const GALGAS_lstring & inOperand2
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlArgumentList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::setter_insertAtIndex (const GALGAS_bool inOperand0,
                                                   const GALGAS_type inOperand1,
                                                   const GALGAS_lstring inOperand2,
                                                   const GALGAS_uint inInsertionIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlArgumentList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::setter_removeAtIndex (GALGAS_bool & outOperand0,
                                                   GALGAS_type & outOperand1,
                                                   GALGAS_lstring & outOperand2,
                                                   const GALGAS_uint inRemoveIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
      outOperand0 = p->mObject.mAttribute_typed ;
      outOperand1 = p->mObject.mAttribute_type ;
      outOperand2 = p->mObject.mAttribute_name ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::setter_popFirst (GALGAS_bool & outOperand0,
                                              GALGAS_type & outOperand1,
                                              GALGAS_lstring & outOperand2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mAttribute_typed ;
    outOperand1 = p->mObject.mAttribute_type ;
    outOperand2 = p->mObject.mAttribute_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::setter_popLast (GALGAS_bool & outOperand0,
                                             GALGAS_type & outOperand1,
                                             GALGAS_lstring & outOperand2,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mAttribute_typed ;
    outOperand1 = p->mObject.mAttribute_type ;
    outOperand2 = p->mObject.mAttribute_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::method_first (GALGAS_bool & outOperand0,
                                           GALGAS_type & outOperand1,
                                           GALGAS_lstring & outOperand2,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mAttribute_typed ;
    outOperand1 = p->mObject.mAttribute_type ;
    outOperand2 = p->mObject.mAttribute_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::method_last (GALGAS_bool & outOperand0,
                                          GALGAS_type & outOperand1,
                                          GALGAS_lstring & outOperand2,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mAttribute_typed ;
    outOperand1 = p->mObject.mAttribute_type ;
    outOperand2 = p->mObject.mAttribute_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::add_operation (const GALGAS_gtlArgumentList & inOperand,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::plusAssign_operation (const GALGAS_gtlArgumentList inOperand,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlArgumentList::getter_typedAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mAttribute_typed ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlArgumentList::getter_typeAtIndex (const GALGAS_uint & inIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_type result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mAttribute_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlArgumentList::getter_nameAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mAttribute_name ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlArgumentList::cEnumerator_gtlArgumentList (const GALGAS_gtlArgumentList & inEnumeratedObject,
                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList_2D_element cEnumerator_gtlArgumentList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_gtlArgumentList::current_typed (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mAttribute_typed ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type cEnumerator_gtlArgumentList::current_type (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mAttribute_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlArgumentList::current_name (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mAttribute_name ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @gtlArgumentList type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlArgumentList ("gtlArgumentList",
                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlArgumentList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlArgumentList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlArgumentList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlArgumentList result ;
  const GALGAS_gtlArgumentList * p = (const GALGAS_gtlArgumentList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlArgumentList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlArgumentList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlProcMap::cMapElement_gtlProcMap (const GALGAS_lstring & inKey,
                                                const GALGAS_gtlProcedure & in_procedure
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_procedure (in_procedure) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlProcMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_procedure.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlProcMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlProcMap (mAttribute_lkey, mAttribute_procedure COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlProcMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "procedure" ":" ;
  mAttribute_procedure.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlProcMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlProcMap * operand = (cMapElement_gtlProcMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_procedure.objectCompare (operand->mAttribute_procedure) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap::GALGAS_gtlProcMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap::GALGAS_gtlProcMap (const GALGAS_gtlProcMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap & GALGAS_gtlProcMap::operator = (const GALGAS_gtlProcMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlProcMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlProcMap::constructor_mapWithMapToOverride (const GALGAS_gtlProcMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlProcMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_gtlProcMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_gtlProcedure & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlProcMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlProcMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_gtlProcedure inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlProcMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a procedure named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlProcMap_get = "there is no procedure named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_gtlProcedure & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_gtlProcMap_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    outArgument0 = p->mAttribute_procedure ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure GALGAS_gtlProcMap::getter_procedureForKey (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) attributes ;
  GALGAS_gtlProcedure result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    result = p->mAttribute_procedure ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap::setter_setProcedureForKey (GALGAS_gtlProcedure inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlProcMap * p = (cMapElement_gtlProcMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    p->mAttribute_procedure = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlProcMap * GALGAS_gtlProcMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * result = (cMapElement_gtlProcMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlProcMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlProcMap::cEnumerator_gtlProcMap (const GALGAS_gtlProcMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap_2D_element cEnumerator_gtlProcMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlProcMap) ;
  return GALGAS_gtlProcMap_2D_element (p->mAttribute_lkey, p->mAttribute_procedure) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlProcMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure cEnumerator_gtlProcMap::current_procedure (LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlProcMap) ;
  return p->mAttribute_procedure ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlProcMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlProcMap ("gtlProcMap",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlProcMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlProcMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlProcMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlProcMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlProcMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  const GALGAS_gtlProcMap * p = (const GALGAS_gtlProcMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlProcMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlProcMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     L E X I Q U E                                                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//---------------------------------------------------------------------------------------------------------------------*

cTokenFor_gtl_5F_scanner::cTokenFor_gtl_5F_scanner (void) :
mLexicalAttribute_a_5F_string (),
mLexicalAttribute_charValue (),
mLexicalAttribute_floatValue (),
mLexicalAttribute_functionContent (),
mLexicalAttribute_identifierString (),
mLexicalAttribute_intValue (),
mLexicalAttribute_tokenString (),
mLexicalAttribute_uint_33__32_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_gtl_5F_scanner::C_Lexique_gtl_5F_scanner (C_Compiler * inCallerCompiler,
                                                    const C_String & inDependencyFileExtension,
                                                    const C_String & inDependencyFilePath,
                                                    const C_String & inSourceFileName
                                                    COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inDependencyFileExtension, inDependencyFilePath, inSourceFileName COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_gtl_5F_scanner::C_Lexique_gtl_5F_scanner (C_Compiler * inCallerCompiler,
                                                    const C_String & inSourceString,
                                                    const C_String & inStringForError
                                                    COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::indexingDirectory (void) const {
  return "" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                        Lexical error message list                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

static const char * gLexicalMessage_gtl_5F_scanner_floatNumberConversionError = "invalid float number" ;

static const char * gLexicalMessage_gtl_5F_scanner_incorrectCharConstant = "incorrect literal character" ;

static const char * gLexicalMessage_gtl_5F_scanner_incorrectHTMLescapeSequence = "Invalid HTML sequence, should be '&...;'" ;

static const char * gLexicalMessage_gtl_5F_scanner_internalError = "internal error" ;

static const char * gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 = "\\u should be followed by exactly four hexadecimal digits" ;

static const char * gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 = "\\U should be followed by exactly eight hexadecimal digits" ;

static const char * gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue = "this value does not correspond to an assigned Unicode point" ;

static const char * gLexicalMessage_gtl_5F_scanner_unknownHTMLescapeSequence = "Invalid &...; HTML sequence" ;

static const char * gLexicalMessage_gtl_5F_scanner_unterminatedLitteralString = "Unterminated literal string" ;

//---------------------------------------------------------------------------------------------------------------------*
//          Syntax error messages, for every terminal symbol                                                           *
//---------------------------------------------------------------------------------------------------------------------*

//--- Syntax error message for terminal '$identifier$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_identifier = "an identifier" ;

//--- Syntax error message for terminal '$literal_enum$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_enum = "a literal enum value" ;

//--- Syntax error message for terminal '$literal_double$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_double = "a float number" ;

//--- Syntax error message for terminal '$signed_literal_integer_bigint$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_signed_5F_literal_5F_integer_5F_bigint = "a bigint decimal number" ;

//--- Syntax error message for terminal '$-$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2D_ = "the - delimitor" ;

//--- Syntax error message for terminal '$.$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2E_ = "the '.' delimitor" ;

//--- Syntax error message for terminal '$.=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2E__3D_ = "the '.=' delimitor" ;

//--- Syntax error message for terminal '$...$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2E__2E__2E_ = "the '...' delimitor" ;

//--- Syntax error message for terminal '$literal_char$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_char = "a character constant" ;

//--- Syntax error message for terminal '$string$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_string = "literal string" ;

//--- Syntax error message for terminal '$comment$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_comment = "a comment" ;

//--- Syntax error message for terminal '$after$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_after = "the 'after' keyword" ;

//--- Syntax error message for terminal '$before$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_before = "the 'before' keyword" ;

//--- Syntax error message for terminal '$between$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_between = "the 'between' keyword" ;

//--- Syntax error message for terminal '$by$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_by = "the 'by' keyword" ;

//--- Syntax error message for terminal '$default$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_default = "the 'default' keyword" ;

//--- Syntax error message for terminal '$display$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_display = "the 'display' keyword" ;

//--- Syntax error message for terminal '$do$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_do = "the 'do' keyword" ;

//--- Syntax error message for terminal '$down$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_down = "the 'down' keyword" ;

//--- Syntax error message for terminal '$else$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_else = "the 'else' keyword" ;

//--- Syntax error message for terminal '$elsif$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_elsif = "the 'elsif' keyword" ;

//--- Syntax error message for terminal '$emptylist$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_emptylist = "the 'emptylist' keyword" ;

//--- Syntax error message for terminal '$emptymap$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_emptymap = "the 'emptymap' keyword" ;

//--- Syntax error message for terminal '$end$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_end = "the 'end' keyword" ;

//--- Syntax error message for terminal '$error$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_error = "the 'error' keyword" ;

//--- Syntax error message for terminal '$exists$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_exists = "the 'exists' keyword" ;

//--- Syntax error message for terminal '$false$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_false = "the 'false' keyword" ;

//--- Syntax error message for terminal '$for$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_for = "the 'for' keyword" ;

//--- Syntax error message for terminal '$foreach$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_foreach = "the 'foreach' keyword" ;

//--- Syntax error message for terminal '$from$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_from = "the 'from' keyword" ;

//--- Syntax error message for terminal '$func$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_func = "the 'func' keyword" ;

//--- Syntax error message for terminal '$here$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_here = "the 'here' keyword" ;

//--- Syntax error message for terminal '$if$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_if = "the 'if' keyword" ;

//--- Syntax error message for terminal '$in$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_in = "the 'in' keyword" ;

//--- Syntax error message for terminal '$import$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_import = "the 'import' keyword" ;

//--- Syntax error message for terminal '$listof$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_listof = "the 'listof' keyword" ;

//--- Syntax error message for terminal '$let$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_let = "the 'let' keyword" ;

//--- Syntax error message for terminal '$loop$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_loop = "the 'loop' keyword" ;

//--- Syntax error message for terminal '$mapof$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_mapof = "the 'mapof' keyword" ;

//--- Syntax error message for terminal '$mod$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_mod = "the 'mod' keyword" ;

//--- Syntax error message for terminal '$no$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_no = "the 'no' keyword" ;

//--- Syntax error message for terminal '$not$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_not = "the 'not' keyword" ;

//--- Syntax error message for terminal '$or$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_or = "the 'or' keyword" ;

//--- Syntax error message for terminal '$print$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_print = "the 'print' keyword" ;

//--- Syntax error message for terminal '$println$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_println = "the 'println' keyword" ;

//--- Syntax error message for terminal '$repeat$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_repeat = "the 'repeat' keyword" ;

//--- Syntax error message for terminal '$sort$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_sort = "the 'sort' keyword" ;

//--- Syntax error message for terminal '$step$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_step = "the 'step' keyword" ;

//--- Syntax error message for terminal '$tab$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_tab = "the 'tab' keyword" ;

//--- Syntax error message for terminal '$template$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_template = "the 'template' keyword" ;

//--- Syntax error message for terminal '$then$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_then = "the 'then' keyword" ;

//--- Syntax error message for terminal '$to$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_to = "the 'to' keyword" ;

//--- Syntax error message for terminal '$true$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_true = "the 'true' keyword" ;

//--- Syntax error message for terminal '$typeof$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_typeof = "the 'typeof' keyword" ;

//--- Syntax error message for terminal '$up$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_up = "the 'up' keyword" ;

//--- Syntax error message for terminal '$yes$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_yes = "the 'yes' keyword" ;

//--- Syntax error message for terminal '$warning$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_warning = "the 'warning' keyword" ;

//--- Syntax error message for terminal '$while$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_while = "the 'while' keyword" ;

//--- Syntax error message for terminal '$write$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_write = "the 'write' keyword" ;

//--- Syntax error message for terminal '$executable$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_executable = "the 'executable' keyword" ;

//--- Syntax error message for terminal '$variables$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_variables = "the 'variables' keyword" ;

//--- Syntax error message for terminal '$getter$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_getter = "the 'getter' keyword" ;

//--- Syntax error message for terminal '$unlet$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_unlet = "the 'unlet' keyword" ;

//--- Syntax error message for terminal '$setter$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_setter = "the 'setter' keyword" ;

//--- Syntax error message for terminal '$libraries$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_libraries = "the 'libraries' keyword" ;

//--- Syntax error message for terminal '$input$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_input = "the 'input' keyword" ;

//--- Syntax error message for terminal '$*$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2A_ = "the '*' delimitor" ;

//--- Syntax error message for terminal '$|$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7C_ = "the '|' delimitor" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2C_ = "the ',' delimitor" ;

//--- Syntax error message for terminal '$+$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2B_ = "the '+' delimitor" ;

//--- Syntax error message for terminal '$::$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3A__3A_ = "the '::' delimitor" ;

//--- Syntax error message for terminal '$>$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3E_ = "the '>' delimitor" ;

//--- Syntax error message for terminal '$:$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3A_ = "the ':' delimitor" ;

//--- Syntax error message for terminal '$($' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__28_ = "the '(' delimitor" ;

//--- Syntax error message for terminal '$)$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__29_ = "the ')' delimitor" ;

//--- Syntax error message for terminal '$->$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2D__3E_ = "the '->' delimitor" ;

//--- Syntax error message for terminal '$?$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3F_ = "the '\?' delimitor" ;

//--- Syntax error message for terminal '$==$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3D__3D_ = "the '==' delimitor" ;

//--- Syntax error message for terminal '$!$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__21_ = "the '!' delimitor" ;

//--- Syntax error message for terminal '$:=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3A__3D_ = "the ':=' delimitor" ;

//--- Syntax error message for terminal '$[$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5B_ = "the '[' delimitor" ;

//--- Syntax error message for terminal '$]$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5D_ = "the ']' delimitor" ;

//--- Syntax error message for terminal '$+=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2B__3D_ = "the '+=' delimitor" ;

//--- Syntax error message for terminal '$-=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2D__3D_ = "the '-=' delimitor" ;

//--- Syntax error message for terminal '$/$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2F_ = "the '/' delimitor" ;

//--- Syntax error message for terminal '$!=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__21__3D_ = "the '!=' delimitor" ;

//--- Syntax error message for terminal '$>=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3E__3D_ = "the '>=' delimitor" ;

//--- Syntax error message for terminal '$&$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__26_ = "the '&' delimitor" ;

//--- Syntax error message for terminal '$<=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C__3D_ = "the '<=' delimitor" ;

//--- Syntax error message for terminal '${$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7B_ = "the '{' delimitor" ;

//--- Syntax error message for terminal '$}$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7D_ = "the '}' delimitor" ;

//--- Syntax error message for terminal '$<$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C_ = "the '<' delimitor" ;

//--- Syntax error message for terminal '$^$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5E_ = "the '^' delimitor" ;

//--- Syntax error message for terminal '$>>$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3E__3E_ = "the '>>' delimitor" ;

//--- Syntax error message for terminal '$~$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7E_ = "the '~' delimitor" ;

//--- Syntax error message for terminal '$<-$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C__2D_ = "the '<-' delimitor" ;

//--- Syntax error message for terminal '$<<$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C__3C_ = "the '<<' delimitor" ;

//--- Syntax error message for terminal '$@$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40_ = "the '@' delimitor" ;

//--- Syntax error message for terminal '$*=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2A__3D_ = "the '*=' delimitor" ;

//--- Syntax error message for terminal '$/=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2F__3D_ = "the '/=' delimitor" ;

//--- Syntax error message for terminal '$&=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__26__3D_ = "the '&=' delimitor" ;

//--- Syntax error message for terminal '$|=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7C__3D_ = "the '|=' delimitor" ;

//--- Syntax error message for terminal '$<<=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C__3C__3D_ = "the '<<=' delimitor" ;

//--- Syntax error message for terminal '$>>=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3E__3E__3D_ = "the '>>=' delimitor" ;

//--- Syntax error message for terminal '$mod=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_mod_3D_ = "the 'mod=' delimitor" ;

//--- Syntax error message for terminal '$^=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5E__3D_ = "the '^=' delimitor" ;

//--- Syntax error message for terminal '$@[$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40__5B_ = "the '@[' delimitor" ;

//--- Syntax error message for terminal '$@($' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40__28_ = "the '@(' delimitor" ;

//--- Syntax error message for terminal '$@{$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40__7B_ = "the '@{' delimitor" ;

//--- Syntax error message for terminal '$[!$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5B__21_ = "the '[!' delimitor" ;

//--- Syntax error message for terminal '$@!$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40__21_ = "the '@!' delimitor" ;

//---------------------------------------------------------------------------------------------------------------------*
//                getMessageForTerminal                                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::getMessageForTerminal (const int16_t inTerminalIndex) const {
  static const char * syntaxErrorMessageArray [112] = {kEndOfSourceLexicalErrorMessage,
    gSyntaxErrorMessage_gtl_5F_scanner_identifier,
    gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_enum,
    gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_double,
    gSyntaxErrorMessage_gtl_5F_scanner_signed_5F_literal_5F_integer_5F_bigint,
    gSyntaxErrorMessage_gtl_5F_scanner__2D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2E_,
    gSyntaxErrorMessage_gtl_5F_scanner__2E__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2E__2E__2E_,
    gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_char,
    gSyntaxErrorMessage_gtl_5F_scanner_string,
    gSyntaxErrorMessage_gtl_5F_scanner_comment,
    gSyntaxErrorMessage_gtl_5F_scanner_after,
    gSyntaxErrorMessage_gtl_5F_scanner_before,
    gSyntaxErrorMessage_gtl_5F_scanner_between,
    gSyntaxErrorMessage_gtl_5F_scanner_by,
    gSyntaxErrorMessage_gtl_5F_scanner_default,
    gSyntaxErrorMessage_gtl_5F_scanner_display,
    gSyntaxErrorMessage_gtl_5F_scanner_do,
    gSyntaxErrorMessage_gtl_5F_scanner_down,
    gSyntaxErrorMessage_gtl_5F_scanner_else,
    gSyntaxErrorMessage_gtl_5F_scanner_elsif,
    gSyntaxErrorMessage_gtl_5F_scanner_emptylist,
    gSyntaxErrorMessage_gtl_5F_scanner_emptymap,
    gSyntaxErrorMessage_gtl_5F_scanner_end,
    gSyntaxErrorMessage_gtl_5F_scanner_error,
    gSyntaxErrorMessage_gtl_5F_scanner_exists,
    gSyntaxErrorMessage_gtl_5F_scanner_false,
    gSyntaxErrorMessage_gtl_5F_scanner_for,
    gSyntaxErrorMessage_gtl_5F_scanner_foreach,
    gSyntaxErrorMessage_gtl_5F_scanner_from,
    gSyntaxErrorMessage_gtl_5F_scanner_func,
    gSyntaxErrorMessage_gtl_5F_scanner_here,
    gSyntaxErrorMessage_gtl_5F_scanner_if,
    gSyntaxErrorMessage_gtl_5F_scanner_in,
    gSyntaxErrorMessage_gtl_5F_scanner_import,
    gSyntaxErrorMessage_gtl_5F_scanner_listof,
    gSyntaxErrorMessage_gtl_5F_scanner_let,
    gSyntaxErrorMessage_gtl_5F_scanner_loop,
    gSyntaxErrorMessage_gtl_5F_scanner_mapof,
    gSyntaxErrorMessage_gtl_5F_scanner_mod,
    gSyntaxErrorMessage_gtl_5F_scanner_no,
    gSyntaxErrorMessage_gtl_5F_scanner_not,
    gSyntaxErrorMessage_gtl_5F_scanner_or,
    gSyntaxErrorMessage_gtl_5F_scanner_print,
    gSyntaxErrorMessage_gtl_5F_scanner_println,
    gSyntaxErrorMessage_gtl_5F_scanner_repeat,
    gSyntaxErrorMessage_gtl_5F_scanner_sort,
    gSyntaxErrorMessage_gtl_5F_scanner_step,
    gSyntaxErrorMessage_gtl_5F_scanner_tab,
    gSyntaxErrorMessage_gtl_5F_scanner_template,
    gSyntaxErrorMessage_gtl_5F_scanner_then,
    gSyntaxErrorMessage_gtl_5F_scanner_to,
    gSyntaxErrorMessage_gtl_5F_scanner_true,
    gSyntaxErrorMessage_gtl_5F_scanner_typeof,
    gSyntaxErrorMessage_gtl_5F_scanner_up,
    gSyntaxErrorMessage_gtl_5F_scanner_yes,
    gSyntaxErrorMessage_gtl_5F_scanner_warning,
    gSyntaxErrorMessage_gtl_5F_scanner_while,
    gSyntaxErrorMessage_gtl_5F_scanner_write,
    gSyntaxErrorMessage_gtl_5F_scanner_executable,
    gSyntaxErrorMessage_gtl_5F_scanner_variables,
    gSyntaxErrorMessage_gtl_5F_scanner_getter,
    gSyntaxErrorMessage_gtl_5F_scanner_unlet,
    gSyntaxErrorMessage_gtl_5F_scanner_setter,
    gSyntaxErrorMessage_gtl_5F_scanner_libraries,
    gSyntaxErrorMessage_gtl_5F_scanner_input,
    gSyntaxErrorMessage_gtl_5F_scanner__2A_,
    gSyntaxErrorMessage_gtl_5F_scanner__7C_,
    gSyntaxErrorMessage_gtl_5F_scanner__2C_,
    gSyntaxErrorMessage_gtl_5F_scanner__2B_,
    gSyntaxErrorMessage_gtl_5F_scanner__3A__3A_,
    gSyntaxErrorMessage_gtl_5F_scanner__3E_,
    gSyntaxErrorMessage_gtl_5F_scanner__3A_,
    gSyntaxErrorMessage_gtl_5F_scanner__28_,
    gSyntaxErrorMessage_gtl_5F_scanner__29_,
    gSyntaxErrorMessage_gtl_5F_scanner__2D__3E_,
    gSyntaxErrorMessage_gtl_5F_scanner__3F_,
    gSyntaxErrorMessage_gtl_5F_scanner__3D__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__21_,
    gSyntaxErrorMessage_gtl_5F_scanner__3A__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__5B_,
    gSyntaxErrorMessage_gtl_5F_scanner__5D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2B__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2D__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2F_,
    gSyntaxErrorMessage_gtl_5F_scanner__21__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3E__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__26_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__7B_,
    gSyntaxErrorMessage_gtl_5F_scanner__7D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C_,
    gSyntaxErrorMessage_gtl_5F_scanner__5E_,
    gSyntaxErrorMessage_gtl_5F_scanner__3E__3E_,
    gSyntaxErrorMessage_gtl_5F_scanner__7E_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C__2D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C__3C_,
    gSyntaxErrorMessage_gtl_5F_scanner__40_,
    gSyntaxErrorMessage_gtl_5F_scanner__2A__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2F__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__26__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__7C__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C__3C__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3E__3E__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner_mod_3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__5E__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__40__5B_,
    gSyntaxErrorMessage_gtl_5F_scanner__40__28_,
    gSyntaxErrorMessage_gtl_5F_scanner__40__7B_,
    gSyntaxErrorMessage_gtl_5F_scanner__5B__21_,
    gSyntaxErrorMessage_gtl_5F_scanner__40__21_} ;
  return syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                      U N I C O D E    S T R I N G S                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

//--- Unicode string for '$_A_$'
static const utf32 kUnicodeString_gtl_5F_scanner__A_ [] = {
  TO_UNICODE (10),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21_$'
static const utf32 kUnicodeString_gtl_5F_scanner__21_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__21__3D_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_25_$'
static const utf32 kUnicodeString_gtl_5F_scanner__25_ [] = {
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_$'
static const utf32 kUnicodeString_gtl_5F_scanner__26_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__26__3D_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_28_$'
static const utf32 kUnicodeString_gtl_5F_scanner__28_ [] = {
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_29_$'
static const utf32 kUnicodeString_gtl_5F_scanner__29_ [] = {
  TO_UNICODE (')'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2A_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2A__3D_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2B_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2B__3D_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2D__3D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2D__3E_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2E__2E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2E__2E_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE ('.'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2F_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2F__3D_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_X$'
static const utf32 kUnicodeString_gtl_5F_scanner__30_X [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('X'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_x$'
static const utf32 kUnicodeString_gtl_5F_scanner__30_x [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A__3A_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3A__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3A__3D_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__2D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C__2D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3C__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C__3C__3D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C__3D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3D__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3E__3D_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3E__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3E__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3E__3E__3D_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3F_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3F_ [] = {
  TO_UNICODE ('\?'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__21_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__21_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__28_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__28_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__5B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__5B_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__7B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__7B_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5B_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B__21_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5B__21_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5C_ [] = {
  TO_UNICODE ('\\'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5C__25_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5C__25_ [] = {
  TO_UNICODE ('\\'),
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5C__5C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5C__5C_ [] = {
  TO_UNICODE ('\\'),
  TO_UNICODE ('\\'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5C_n$'
static const utf32 kUnicodeString_gtl_5F_scanner__5C_n [] = {
  TO_UNICODE ('\\'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5D_ [] = {
  TO_UNICODE (']'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5E_ [] = {
  TO_UNICODE ('^'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5E__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5E__3D_ [] = {
  TO_UNICODE ('^'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$after$'
static const utf32 kUnicodeString_gtl_5F_scanner_after [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('f'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$before$'
static const utf32 kUnicodeString_gtl_5F_scanner_before [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$between$'
static const utf32 kUnicodeString_gtl_5F_scanner_between [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('w'),
  TO_UNICODE ('e'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$by$'
static const utf32 kUnicodeString_gtl_5F_scanner_by [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$default$'
static const utf32 kUnicodeString_gtl_5F_scanner_default [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$display$'
static const utf32 kUnicodeString_gtl_5F_scanner_display [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('a'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$do$'
static const utf32 kUnicodeString_gtl_5F_scanner_do [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$down$'
static const utf32 kUnicodeString_gtl_5F_scanner_down [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('o'),
  TO_UNICODE ('w'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$else$'
static const utf32 kUnicodeString_gtl_5F_scanner_else [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$elsif$'
static const utf32 kUnicodeString_gtl_5F_scanner_elsif [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$emptylist$'
static const utf32 kUnicodeString_gtl_5F_scanner_emptylist [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$emptymap$'
static const utf32 kUnicodeString_gtl_5F_scanner_emptymap [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$end$'
static const utf32 kUnicodeString_gtl_5F_scanner_end [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$error$'
static const utf32 kUnicodeString_gtl_5F_scanner_error [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$executable$'
static const utf32 kUnicodeString_gtl_5F_scanner_executable [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('e'),
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('b'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$exists$'
static const utf32 kUnicodeString_gtl_5F_scanner_exists [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$false$'
static const utf32 kUnicodeString_gtl_5F_scanner_false [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$for$'
static const utf32 kUnicodeString_gtl_5F_scanner_for [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$foreach$'
static const utf32 kUnicodeString_gtl_5F_scanner_foreach [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$from$'
static const utf32 kUnicodeString_gtl_5F_scanner_from [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$func$'
static const utf32 kUnicodeString_gtl_5F_scanner_func [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$getter$'
static const utf32 kUnicodeString_gtl_5F_scanner_getter [] = {
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$here$'
static const utf32 kUnicodeString_gtl_5F_scanner_here [] = {
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$if$'
static const utf32 kUnicodeString_gtl_5F_scanner_if [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$import$'
static const utf32 kUnicodeString_gtl_5F_scanner_import [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$in$'
static const utf32 kUnicodeString_gtl_5F_scanner_in [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$input$'
static const utf32 kUnicodeString_gtl_5F_scanner_input [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('p'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$let$'
static const utf32 kUnicodeString_gtl_5F_scanner_let [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$libraries$'
static const utf32 kUnicodeString_gtl_5F_scanner_libraries [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$listof$'
static const utf32 kUnicodeString_gtl_5F_scanner_listof [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$loop$'
static const utf32 kUnicodeString_gtl_5F_scanner_loop [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('o'),
  TO_UNICODE ('o'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mapof$'
static const utf32 kUnicodeString_gtl_5F_scanner_mapof [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mod$'
static const utf32 kUnicodeString_gtl_5F_scanner_mod [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mod_3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner_mod_3D_ [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$no$'
static const utf32 kUnicodeString_gtl_5F_scanner_no [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$not$'
static const utf32 kUnicodeString_gtl_5F_scanner_not [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$or$'
static const utf32 kUnicodeString_gtl_5F_scanner_or [] = {
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$print$'
static const utf32 kUnicodeString_gtl_5F_scanner_print [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$println$'
static const utf32 kUnicodeString_gtl_5F_scanner_println [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('l'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$repeat$'
static const utf32 kUnicodeString_gtl_5F_scanner_repeat [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$setter$'
static const utf32 kUnicodeString_gtl_5F_scanner_setter [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$sort$'
static const utf32 kUnicodeString_gtl_5F_scanner_sort [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$step$'
static const utf32 kUnicodeString_gtl_5F_scanner_step [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$tab$'
static const utf32 kUnicodeString_gtl_5F_scanner_tab [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('b'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$template$'
static const utf32 kUnicodeString_gtl_5F_scanner_template [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$then$'
static const utf32 kUnicodeString_gtl_5F_scanner_then [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$to$'
static const utf32 kUnicodeString_gtl_5F_scanner_to [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$true$'
static const utf32 kUnicodeString_gtl_5F_scanner_true [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$typeof$'
static const utf32 kUnicodeString_gtl_5F_scanner_typeof [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$unlet$'
static const utf32 kUnicodeString_gtl_5F_scanner_unlet [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$up$'
static const utf32 kUnicodeString_gtl_5F_scanner_up [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$variables$'
static const utf32 kUnicodeString_gtl_5F_scanner_variables [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('a'),
  TO_UNICODE ('b'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$warning$'
static const utf32 kUnicodeString_gtl_5F_scanner_warning [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('n'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$while$'
static const utf32 kUnicodeString_gtl_5F_scanner_while [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('h'),
  TO_UNICODE ('i'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$write$'
static const utf32 kUnicodeString_gtl_5F_scanner_write [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$yes$'
static const utf32 kUnicodeString_gtl_5F_scanner_yes [] = {
  TO_UNICODE ('y'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7B_ [] = {
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7C_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7C__3D_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7D_ [] = {
  TO_UNICODE ('}'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7E_ [] = {
  TO_UNICODE ('~'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'galgasDelimitorsList'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_gtl_5F_scanner_galgasDelimitorsList = 45 ;

static const C_unicode_lexique_table_entry ktable_for_gtl_5F_scanner_galgasDelimitorsList [ktable_size_gtl_5F_scanner_galgasDelimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__21_, 1, C_Lexique_gtl_5F_scanner::kToken__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__26_, 1, C_Lexique_gtl_5F_scanner::kToken__26_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__28_, 1, C_Lexique_gtl_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__29_, 1, C_Lexique_gtl_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2A_, 1, C_Lexique_gtl_5F_scanner::kToken__2A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2B_, 1, C_Lexique_gtl_5F_scanner::kToken__2B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2C_, 1, C_Lexique_gtl_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2F_, 1, C_Lexique_gtl_5F_scanner::kToken__2F_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3A_, 1, C_Lexique_gtl_5F_scanner::kToken__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C_, 1, C_Lexique_gtl_5F_scanner::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E_, 1, C_Lexique_gtl_5F_scanner::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3F_, 1, C_Lexique_gtl_5F_scanner::kToken__3F_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40_, 1, C_Lexique_gtl_5F_scanner::kToken__40_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5B_, 1, C_Lexique_gtl_5F_scanner::kToken__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5D_, 1, C_Lexique_gtl_5F_scanner::kToken__5D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5E_, 1, C_Lexique_gtl_5F_scanner::kToken__5E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7B_, 1, C_Lexique_gtl_5F_scanner::kToken__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7C_, 1, C_Lexique_gtl_5F_scanner::kToken__7C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7D_, 1, C_Lexique_gtl_5F_scanner::kToken__7D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7E_, 1, C_Lexique_gtl_5F_scanner::kToken__7E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__21__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__21__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__26__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__26__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2A__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__2A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2B__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__2B__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2D__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__2D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2D__3E_, 2, C_Lexique_gtl_5F_scanner::kToken__2D__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2F__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__2F__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3A__3A_, 2, C_Lexique_gtl_5F_scanner::kToken__3A__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3A__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__3A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__2D_, 2, C_Lexique_gtl_5F_scanner::kToken__3C__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__3C_, 2, C_Lexique_gtl_5F_scanner::kToken__3C__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3D__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__3D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__3E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E__3E_, 2, C_Lexique_gtl_5F_scanner::kToken__3E__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__21_, 2, C_Lexique_gtl_5F_scanner::kToken__40__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__28_, 2, C_Lexique_gtl_5F_scanner::kToken__40__28_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__5B_, 2, C_Lexique_gtl_5F_scanner::kToken__40__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__7B_, 2, C_Lexique_gtl_5F_scanner::kToken__40__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5B__21_, 2, C_Lexique_gtl_5F_scanner::kToken__5B__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5E__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__5E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7C__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__7C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__3C__3D_, 3, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E__3E__3D_, 3, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_mod_3D_, 4, C_Lexique_gtl_5F_scanner::kToken_mod_3D_)
} ;

int16_t C_Lexique_gtl_5F_scanner::search_into_galgasDelimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_gtl_5F_scanner_galgasDelimitorsList, ktable_size_gtl_5F_scanner_galgasDelimitorsList) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'goilTemplateKeyWordList'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_gtl_5F_scanner_goilTemplateKeyWordList = 55 ;

static const C_unicode_lexique_table_entry ktable_for_gtl_5F_scanner_goilTemplateKeyWordList [ktable_size_gtl_5F_scanner_goilTemplateKeyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_by, 2, C_Lexique_gtl_5F_scanner::kToken_by),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_do, 2, C_Lexique_gtl_5F_scanner::kToken_do),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_if, 2, C_Lexique_gtl_5F_scanner::kToken_if),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_in, 2, C_Lexique_gtl_5F_scanner::kToken_in),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_no, 2, C_Lexique_gtl_5F_scanner::kToken_no),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_or, 2, C_Lexique_gtl_5F_scanner::kToken_or),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_to, 2, C_Lexique_gtl_5F_scanner::kToken_to),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_up, 2, C_Lexique_gtl_5F_scanner::kToken_up),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_end, 3, C_Lexique_gtl_5F_scanner::kToken_end),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_for, 3, C_Lexique_gtl_5F_scanner::kToken_for),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_let, 3, C_Lexique_gtl_5F_scanner::kToken_let),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_mod, 3, C_Lexique_gtl_5F_scanner::kToken_mod),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_not, 3, C_Lexique_gtl_5F_scanner::kToken_not),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_tab, 3, C_Lexique_gtl_5F_scanner::kToken_tab),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_yes, 3, C_Lexique_gtl_5F_scanner::kToken_yes),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_down, 4, C_Lexique_gtl_5F_scanner::kToken_down),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_else, 4, C_Lexique_gtl_5F_scanner::kToken_else),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_from, 4, C_Lexique_gtl_5F_scanner::kToken_from),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_func, 4, C_Lexique_gtl_5F_scanner::kToken_func),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_here, 4, C_Lexique_gtl_5F_scanner::kToken_here),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_loop, 4, C_Lexique_gtl_5F_scanner::kToken_loop),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_sort, 4, C_Lexique_gtl_5F_scanner::kToken_sort),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_step, 4, C_Lexique_gtl_5F_scanner::kToken_step),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_then, 4, C_Lexique_gtl_5F_scanner::kToken_then),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_true, 4, C_Lexique_gtl_5F_scanner::kToken_true),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_after, 5, C_Lexique_gtl_5F_scanner::kToken_after),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_elsif, 5, C_Lexique_gtl_5F_scanner::kToken_elsif),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_error, 5, C_Lexique_gtl_5F_scanner::kToken_error),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_false, 5, C_Lexique_gtl_5F_scanner::kToken_false),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_input, 5, C_Lexique_gtl_5F_scanner::kToken_input),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_mapof, 5, C_Lexique_gtl_5F_scanner::kToken_mapof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_print, 5, C_Lexique_gtl_5F_scanner::kToken_print),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_unlet, 5, C_Lexique_gtl_5F_scanner::kToken_unlet),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_while, 5, C_Lexique_gtl_5F_scanner::kToken_while),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_write, 5, C_Lexique_gtl_5F_scanner::kToken_write),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_before, 6, C_Lexique_gtl_5F_scanner::kToken_before),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_exists, 6, C_Lexique_gtl_5F_scanner::kToken_exists),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_getter, 6, C_Lexique_gtl_5F_scanner::kToken_getter),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_import, 6, C_Lexique_gtl_5F_scanner::kToken_import),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_listof, 6, C_Lexique_gtl_5F_scanner::kToken_listof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_repeat, 6, C_Lexique_gtl_5F_scanner::kToken_repeat),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_setter, 6, C_Lexique_gtl_5F_scanner::kToken_setter),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_typeof, 6, C_Lexique_gtl_5F_scanner::kToken_typeof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_between, 7, C_Lexique_gtl_5F_scanner::kToken_between),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_default, 7, C_Lexique_gtl_5F_scanner::kToken_default),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_display, 7, C_Lexique_gtl_5F_scanner::kToken_display),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_foreach, 7, C_Lexique_gtl_5F_scanner::kToken_foreach),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_println, 7, C_Lexique_gtl_5F_scanner::kToken_println),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_warning, 7, C_Lexique_gtl_5F_scanner::kToken_warning),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_emptymap, 8, C_Lexique_gtl_5F_scanner::kToken_emptymap),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_template, 8, C_Lexique_gtl_5F_scanner::kToken_template),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_emptylist, 9, C_Lexique_gtl_5F_scanner::kToken_emptylist),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_libraries, 9, C_Lexique_gtl_5F_scanner::kToken_libraries),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_variables, 9, C_Lexique_gtl_5F_scanner::kToken_variables),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_executable, 10, C_Lexique_gtl_5F_scanner::kToken_executable)
} ;

int16_t C_Lexique_gtl_5F_scanner::search_into_goilTemplateKeyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_gtl_5F_scanner_goilTemplateKeyWordList, ktable_size_gtl_5F_scanner_goilTemplateKeyWordList) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                          getCurrentTokenString                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_gtl_5F_scanner * ptr = (const cTokenFor_gtl_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_identifier:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("identifier") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_literal_5F_enum:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_enum") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_literal_5F_double:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_double") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendDouble (ptr->mLexicalAttribute_floatValue) ;
      break ;
    case kToken_signed_5F_literal_5F_integer_5F_bigint:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("signed_literal_integer_bigint") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_intValue.decimalString ()) ;
      break ;
    case kToken__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (".") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (".=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E__2E__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("...") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_literal_5F_char:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_char") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendUnicodeCharacter (ptr->mLexicalAttribute_charValue COMMA_HERE) ;
      break ;
    case kToken_string:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("string") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_a_5F_string) ;
      break ;
    case kToken_comment:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("comment") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_after:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("after") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_before:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("before") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_between:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("between") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_by:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("by") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_default:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("default") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_display:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("display") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_do:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("do") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_down:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("down") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_else:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("else") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_elsif:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("elsif") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_emptylist:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("emptylist") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_emptymap:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("emptymap") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_end:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("end") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_error:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("error") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_exists:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("exists") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_false:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("false") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_for:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("for") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_foreach:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("foreach") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_from:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("from") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_func:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("func") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_here:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("here") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_if:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("if") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_in:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("in") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_import:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("import") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_listof:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("listof") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_let:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("let") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_loop:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("loop") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_mapof:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("mapof") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_mod:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("mod") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_no:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("no") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_not:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("not") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_or:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("or") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_print:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("print") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_println:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("println") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_repeat:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("repeat") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_sort:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("sort") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_step:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("step") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_tab:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("tab") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_template:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("template") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_then:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("then") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_to:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("to") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_true:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("true") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_typeof:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("typeof") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_up:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("up") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_yes:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("yes") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_warning:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("warning") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_while:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("while") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_write:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("write") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_executable:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("executable") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_variables:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("variables") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_getter:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("getter") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_unlet:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("unlet") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_setter:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("setter") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_libraries:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("libraries") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_input:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("input") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("*") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("|") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (",") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A__3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("::") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (":") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__28_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("(") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__29_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (")") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("->") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\?") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("==") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (":=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("[") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("]") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__26_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("&") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("{") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("}") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("^") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("~") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<-") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2A__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("*=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__26__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("&=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("|=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<<=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">>=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_mod_3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("mod=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("^=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40__5B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@[") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40__28_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@(") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40__7B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@{") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5B__21_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("[!") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__40__21_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@!") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                           Template Delimiters                                                                       *
//---------------------------------------------------------------------------------------------------------------------*

static const cTemplateDelimiter kTemplateDefinitionArray [1] = {
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__25_, 1, kUnicodeString_gtl_5F_scanner__25_, 1, NULL, true)
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                           Template Replacements                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const cTemplateDelimiter kTemplateReplacementArray [3] = {
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C__25_, 2, kUnicodeString_gtl_5F_scanner__25_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C_n, 2, kUnicodeString_gtl_5F_scanner__A_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C__5C_, 2, kUnicodeString_gtl_5F_scanner__5C_, 1, NULL, true)
} ;

//---------------------------------------------------------------------------------------------------------------------*
//            Terminal Symbols as end of script in template mark                                                       *
//---------------------------------------------------------------------------------------------------------------------*

static const bool kEndOfScriptInTemplateArray [111] = {
  false /* identifier */,
  false /* literal_enum */,
  false /* literal_double */,
  false /* signed_literal_integer_bigint */,
  false /* - */,
  false /* . */,
  false /* .= */,
  false /* ... */,
  false /* literal_char */,
  false /* string */,
  false /* comment */,
  false /* after */,
  false /* before */,
  false /* between */,
  false /* by */,
  false /* default */,
  false /* display */,
  false /* do */,
  false /* down */,
  false /* else */,
  false /* elsif */,
  false /* emptylist */,
  false /* emptymap */,
  false /* end */,
  false /* error */,
  false /* exists */,
  false /* false */,
  false /* for */,
  false /* foreach */,
  false /* from */,
  false /* func */,
  false /* here */,
  false /* if */,
  false /* in */,
  false /* import */,
  false /* listof */,
  false /* let */,
  false /* loop */,
  false /* mapof */,
  false /* mod */,
  false /* no */,
  false /* not */,
  false /* or */,
  false /* print */,
  false /* println */,
  false /* repeat */,
  false /* sort */,
  false /* step */,
  false /* tab */,
  false /* template */,
  false /* then */,
  false /* to */,
  false /* true */,
  false /* typeof */,
  false /* up */,
  false /* yes */,
  false /* warning */,
  false /* while */,
  false /* write */,
  false /* executable */,
  false /* variables */,
  false /* getter */,
  false /* unlet */,
  false /* setter */,
  false /* libraries */,
  false /* input */,
  false /* * */,
  false /* | */,
  false /* , */,
  false /* + */,
  false /* :: */,
  false /* > */,
  false /* : */,
  false /* ( */,
  false /* ) */,
  false /* -> */,
  false /* ? */,
  false /* == */,
  false /* ! */,
  false /* := */,
  false /* [ */,
  false /* ] */,
  false /* += */,
  false /* -= */,
  false /* / */,
  false /* != */,
  false /* >= */,
  false /* & */,
  false /* <= */,
  false /* { */,
  false /* } */,
  false /* < */,
  false /* ^ */,
  false /* >> */,
  false /* ~ */,
  false /* <- */,
  false /* << */,
  false /* @ */,
  false /* *= */,
  false /* /= */,
  false /* &= */,
  false /* |= */,
  false /* <<= */,
  false /* >>= */,
  false /* mod= */,
  false /* ^= */,
  false /* @[ */,
  false /* @( */,
  false /* @{ */,
  false /* [! */,
  false /* @! */
} ;


//---------------------------------------------------------------------------------------------------------------------*
//               P A R S E    L E X I C A L    T O K E N                                                               *
//---------------------------------------------------------------------------------------------------------------------*

bool C_Lexique_gtl_5F_scanner::parseLexicalToken (void) {
  cTokenFor_gtl_5F_scanner token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    if ((mMatchedTemplateDelimiterIndex >= 0)
     && (kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength > 0)
     && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      const bool foundEndDelimitor = testForInputUTF32String (kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndString,
                                                              kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength,
                                                              true) ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      int32_t replacementIndex = 0 ;
      while (replacementIndex >= 0) {
        replacementIndex = findTemplateDelimiterIndex (kTemplateReplacementArray, 3) ;
        if (replacementIndex >= 0) {
          if (kTemplateReplacementArray [replacementIndex].mReplacementFunction == NULL) {
            token.mTemplateStringBeforeToken << kTemplateReplacementArray [replacementIndex].mEndString ;
          }else{
            C_String s ;
            while (notTestForInputUTF32String (kTemplateReplacementArray [replacementIndex].mEndString,
                                               kTemplateReplacementArray [replacementIndex].mEndStringLength,
                                               kEndOfSourceLexicalErrorMessage
                                               COMMA_HERE)) {
              s.appendUnicodeCharacter (previousChar () COMMA_HERE) ;
            }
            kTemplateReplacementArray [replacementIndex].mReplacementFunction (*this, s, token.mTemplateStringBeforeToken) ;
          }
        }
      }
      mMatchedTemplateDelimiterIndex = findTemplateDelimiterIndex (kTemplateDefinitionArray, 1) ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        token.mTemplateStringBeforeToken.appendUnicodeCharacter (mCurrentChar COMMA_HERE) ;
        advance () ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    token.mLexicalAttribute_a_5F_string.setLengthToZero () ;
    token.mLexicalAttribute_charValue = TO_UNICODE (0) ;
    token.mLexicalAttribute_floatValue = 0.0 ;
    token.mLexicalAttribute_functionContent.setLengthToZero () ;
    token.mLexicalAttribute_identifierString.setLengthToZero () ;
    token.mLexicalAttribute_intValue.setToZero () ;
    token.mLexicalAttribute_tokenString.setLengthToZero () ;
    token.mLexicalAttribute_uint_33__32_value = 0 ;
    mTokenStartLocation = mCurrentLocation ;
    try{
        if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_identifierString, previousChar ()) ;
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          if (token.mTokenCode == -1) {
            token.mTokenCode = search_into_goilTemplateKeyWordList (token.mLexicalAttribute_identifierString) ;
          }
          if (token.mTokenCode == -1) {
            token.mTokenCode = kToken_identifier ;
          }
          enterToken (token) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('$'))) {
          do {
            if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          token.mTokenCode = kToken_literal_5F_enum ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner_mod_3D_, 4, true)) {
          token.mTokenCode = kToken_mod_3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3E__3E__3D_, 3, true)) {
          token.mTokenCode = kToken__3E__3E__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C__3C__3D_, 3, true)) {
          token.mTokenCode = kToken__3C__3C__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7C__3D_, 2, true)) {
          token.mTokenCode = kToken__7C__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5E__3D_, 2, true)) {
          token.mTokenCode = kToken__5E__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5B__21_, 2, true)) {
          token.mTokenCode = kToken__5B__21_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__7B_, 2, true)) {
          token.mTokenCode = kToken__40__7B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__5B_, 2, true)) {
          token.mTokenCode = kToken__40__5B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__28_, 2, true)) {
          token.mTokenCode = kToken__40__28_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__21_, 2, true)) {
          token.mTokenCode = kToken__40__21_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3E__3E_, 2, true)) {
          token.mTokenCode = kToken__3E__3E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3E__3D_, 2, true)) {
          token.mTokenCode = kToken__3E__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3D__3D_, 2, true)) {
          token.mTokenCode = kToken__3D__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C__3D_, 2, true)) {
          token.mTokenCode = kToken__3C__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C__3C_, 2, true)) {
          token.mTokenCode = kToken__3C__3C_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C__2D_, 2, true)) {
          token.mTokenCode = kToken__3C__2D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3A__3D_, 2, true)) {
          token.mTokenCode = kToken__3A__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3A__3A_, 2, true)) {
          token.mTokenCode = kToken__3A__3A_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2F__3D_, 2, true)) {
          token.mTokenCode = kToken__2F__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2D__3E_, 2, true)) {
          token.mTokenCode = kToken__2D__3E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2D__3D_, 2, true)) {
          token.mTokenCode = kToken__2D__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2B__3D_, 2, true)) {
          token.mTokenCode = kToken__2B__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2A__3D_, 2, true)) {
          token.mTokenCode = kToken__2A__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__26__3D_, 2, true)) {
          token.mTokenCode = kToken__26__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__21__3D_, 2, true)) {
          token.mTokenCode = kToken__21__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7E_, 1, true)) {
          token.mTokenCode = kToken__7E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7D_, 1, true)) {
          token.mTokenCode = kToken__7D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7C_, 1, true)) {
          token.mTokenCode = kToken__7C_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7B_, 1, true)) {
          token.mTokenCode = kToken__7B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5E_, 1, true)) {
          token.mTokenCode = kToken__5E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5D_, 1, true)) {
          token.mTokenCode = kToken__5D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5B_, 1, true)) {
          token.mTokenCode = kToken__5B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40_, 1, true)) {
          token.mTokenCode = kToken__40_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3F_, 1, true)) {
          token.mTokenCode = kToken__3F_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3E_, 1, true)) {
          token.mTokenCode = kToken__3E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C_, 1, true)) {
          token.mTokenCode = kToken__3C_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3A_, 1, true)) {
          token.mTokenCode = kToken__3A_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2F_, 1, true)) {
          token.mTokenCode = kToken__2F_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2C_, 1, true)) {
          token.mTokenCode = kToken__2C_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2B_, 1, true)) {
          token.mTokenCode = kToken__2B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2A_, 1, true)) {
          token.mTokenCode = kToken__2A_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__29_, 1, true)) {
          token.mTokenCode = kToken__29_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__28_, 1, true)) {
          token.mTokenCode = kToken__28_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__26_, 1, true)) {
          token.mTokenCode = kToken__26_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__21_, 1, true)) {
          token.mTokenCode = kToken__21_ ;
          enterToken (token) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('-'))) {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('-')) ;
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            do {
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
              }else{
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
            if (testForInputUTF32Char (TO_UNICODE ('.'))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('.')) ;
              do {
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
                  ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
                }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
                }else{
                  mLoop = false ;
                }
              }while (mLoop) ;
              mLoop = true ;
              ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_scanner_floatNumberConversionError) ;
              token.mTokenCode = kToken_literal_5F_double ;
              enterToken (token) ;
            }else{
              ::scanner_routine_convertDecimalStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_scanner_internalError) ;
              token.mTokenCode = kToken_signed_5F_literal_5F_integer_5F_bigint ;
              enterToken (token) ;
            }
          }else{
            token.mTokenCode = kToken__2D_ ;
            enterToken (token) ;
          }
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__30_x, 2, true) || testForInputUTF32String (kUnicodeString_gtl_5F_scanner__30_X, 2, true)) {
          do {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          ::scanner_routine_convertHexStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_scanner_internalError) ;
          token.mTokenCode = kToken_signed_5F_literal_5F_integer_5F_bigint ;
          enterToken (token) ;
        }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          do {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          if (testForInputUTF32Char (TO_UNICODE ('.'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('.')) ;
            do {
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
              }else{
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
            ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_scanner_floatNumberConversionError) ;
            token.mTokenCode = kToken_literal_5F_double ;
            enterToken (token) ;
          }else{
            ::scanner_routine_convertDecimalStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_scanner_internalError) ;
            token.mTokenCode = kToken_signed_5F_literal_5F_integer_5F_bigint ;
            enterToken (token) ;
          }
        }else if (testForInputUTF32Char (TO_UNICODE ('.'))) {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('0')) ;
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('.')) ;
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            do {
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
              }else{
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
            ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_scanner_floatNumberConversionError) ;
            token.mTokenCode = kToken_literal_5F_double ;
            enterToken (token) ;
          }else{
            if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2E__2E_, 2, true)) {
              token.mTokenCode = kToken__2E__2E__2E_ ;
              enterToken (token) ;
            }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3D_, 1, true)) {
              token.mTokenCode = kToken__2E__3D_ ;
              enterToken (token) ;
            }else{
              token.mTokenCode = kToken__2E_ ;
              enterToken (token) ;
            }
          }
        }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
          if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
            if (testForInputUTF32Char (TO_UNICODE ('f'))) {
              ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\f')) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('n'))) {
              ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\n')) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('r'))) {
              ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\r')) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('t'))) {
              ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\t')) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('v'))) {
              ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\v')) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
              ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\\')) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('0'))) {
              ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\0')) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
              ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, TO_UNICODE ('\'')) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('u'))) {
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                      ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue) ;
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else if (testForInputUTF32Char (TO_UNICODE ('U'))) {
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                        ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                          ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                            ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                              ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                              ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue) ;
                            }else{
                              lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                            }
                          }else{
                            lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                          }
                        }else{
                          lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                        }
                      }else{
                        lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                      }
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else if (testForInputUTF32Char (TO_UNICODE ('&'))) {
              do {
                if (notTestForInputUTF32String (kUnicodeString_gtl_5F_scanner__3B_, 1, gLexicalMessage_gtl_5F_scanner_incorrectHTMLescapeSequence COMMA_LINE_AND_SOURCE_FILE)) {
                  ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
                }else{
                  mLoop = false ;
                }
              }while (mLoop) ;
              mLoop = true ;
              ::scanner_routine_convertHTMLSequenceToUnicodeCharacter (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unknownHTMLescapeSequence) ;
            }else{
              lexicalError (gLexicalMessage_gtl_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
            }
          }else if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE (65533))) {
            ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, previousChar ()) ;
          }else{
            lexicalError (gLexicalMessage_gtl_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
          }
          if (testForInputUTF32Char (TO_UNICODE ('\''))) {
            token.mTokenCode = kToken_literal_5F_char ;
            enterToken (token) ;
          }else{
            lexicalError (gLexicalMessage_gtl_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
          }
        }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
          do {
            if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
              if (testForInputUTF32Char (TO_UNICODE ('f'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\f')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('n'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\n')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('r'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\r')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('t'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\t')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('v'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\v')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('\\'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\\')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\"')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\'')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('\?'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, TO_UNICODE ('\?')) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('&'))) {
                do {
                  if (notTestForInputUTF32String (kUnicodeString_gtl_5F_scanner__3B_, 1, gLexicalMessage_gtl_5F_scanner_incorrectHTMLescapeSequence COMMA_LINE_AND_SOURCE_FILE)) {
                    ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_identifierString, previousChar ()) ;
                  }else{
                    mLoop = false ;
                  }
                }while (mLoop) ;
                mLoop = true ;
                ::scanner_routine_convertHTMLSequenceToUnicodeCharacter (*this, token.mLexicalAttribute_identifierString, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unknownHTMLescapeSequence) ;
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('u'))) {
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                        ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                        ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue) ;
                        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
                      }else{
                        lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                      }
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else if (testForInputUTF32Char (TO_UNICODE ('U'))) {
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                        ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                          ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                            ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                              ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                                ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue) ;
                                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
                              }else{
                                lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                              }
                            }else{
                              lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                            }
                          }else{
                            lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                          }
                        }else{
                          lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                        }
                      }else{
                        lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                      }
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else if (testForInputUTF32Char (TO_UNICODE (' ')) || testForInputUTF32Char (TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, previousChar ()) ;
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
            token.mTokenCode = kToken_string ;
            enterToken (token) ;
          }else{
            lexicalError (gLexicalMessage_gtl_5F_scanner_unterminatedLitteralString COMMA_LINE_AND_SOURCE_FILE) ;
          }
        }else if (testForInputUTF32Char (TO_UNICODE ('#'))) {
          do {
            if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          enterDroppedTerminal (kToken_comment) ;
        }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
        }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
          token.mTokenCode = kToken_ ; // Empty string code
        }else{ // Unknown input character
          unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
        }
      }catch (const C_lexicalErrorException &) {
        token.mTokenCode = -1 ; // No token
        advance () ; // ... go throught unknown character
      }
    }
    if ((token.mTokenCode > 0) && kEndOfScriptInTemplateArray [token.mTokenCode - 1]) {
      mMatchedTemplateDelimiterIndex = -1 ;
    }
  
  }
  if ((UNICODE_VALUE (mCurrentChar) == '\0') && (token.mTemplateStringBeforeToken.length () > 0)) {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         E N T E R    T O K E N                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

void C_Lexique_gtl_5F_scanner::enterToken (cTokenFor_gtl_5F_scanner & ioToken) {
  cTokenFor_gtl_5F_scanner * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_gtl_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_a_5F_string = ioToken.mLexicalAttribute_a_5F_string ;
  ptr->mLexicalAttribute_charValue = ioToken.mLexicalAttribute_charValue ;
  ptr->mLexicalAttribute_floatValue = ioToken.mLexicalAttribute_floatValue ;
  ptr->mLexicalAttribute_functionContent = ioToken.mLexicalAttribute_functionContent ;
  ptr->mLexicalAttribute_identifierString = ioToken.mLexicalAttribute_identifierString ;
  ptr->mLexicalAttribute_intValue = ioToken.mLexicalAttribute_intValue ;
  ptr->mLexicalAttribute_tokenString = ioToken.mLexicalAttribute_tokenString ;
  ptr->mLexicalAttribute_uint_33__32_value = ioToken.mLexicalAttribute_uint_33__32_value ;
  enterTokenFromPointer (ptr) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//               A T T R I B U T E   A C C E S S                                                                       *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::attributeValue_a_5F_string (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_a_5F_string ;
}

//---------------------------------------------------------------------------------------------------------------------*

utf32 C_Lexique_gtl_5F_scanner::attributeValue_charValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_charValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

double C_Lexique_gtl_5F_scanner::attributeValue_floatValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_floatValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::attributeValue_functionContent (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_functionContent ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::attributeValue_identifierString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_identifierString ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BigInt C_Lexique_gtl_5F_scanner::attributeValue_intValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_intValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::attributeValue_tokenString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_tokenString ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_Lexique_gtl_5F_scanner::attributeValue_uint_33__32_value (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_uint_33__32_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//         A S S I G N    F R O M    A T T R I B U T E                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_a_5F_string (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_a_5F_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lchar C_Lexique_gtl_5F_scanner::synthetizedAttribute_charValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_char value (ptr->mLexicalAttribute_charValue) ;
  GALGAS_lchar result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ldouble C_Lexique_gtl_5F_scanner::synthetizedAttribute_floatValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatValue) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_functionContent (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_functionContent) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_identifierString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_identifierString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint C_Lexique_gtl_5F_scanner::synthetizedAttribute_intValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_bigint value (ptr->mLexicalAttribute_intValue) ;
  GALGAS_lbigint result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_tokenString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint C_Lexique_gtl_5F_scanner::synthetizedAttribute_uint_33__32_value (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint value (ptr->mLexicalAttribute_uint_33__32_value) ;
  GALGAS_luint result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         I N T R O S P E C T I O N                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist C_Lexique_gtl_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_enum") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_double") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("signed_literal_integer_bigint") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (".") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (".=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("...") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_char") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("string") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("comment") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("after") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("before") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("between") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("by") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("default") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("display") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("do") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("down") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("else") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("elsif") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("emptylist") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("emptymap") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("end") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("error") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("exists") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("false") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("for") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("foreach") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("from") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("func") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("here") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("if") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("in") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("import") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("listof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("let") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("loop") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mapof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mod") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("no") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("not") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("or") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("print") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("println") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("repeat") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("sort") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("step") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("tab") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("template") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("then") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("to") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("true") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("typeof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("up") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("yes") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("warning") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("while") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("write") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("executable") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("variables") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("getter") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("unlet") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("setter") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("libraries") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("input") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("*") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("|") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("::") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (":") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("(") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (")") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("->") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\?") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("==") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (":=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("[") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("]") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("&") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("{") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("}") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("^") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("~") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("*=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("&=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("|=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<<=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">>=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mod=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("^=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@[") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@(") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@{") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("[!") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@!") COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordLists_gtl_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.addObject ("gtl_scanner:galgasDelimitorsList") ;
  ioList.addObject ("gtl_scanner:goilTemplateKeyWordList") ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordsForIdentifier_gtl_5F_scanner (const C_String & inIdentifier,
                                                     bool & ioFound,
                                                     TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "gtl_scanner:galgasDelimitorsList") {
    ioFound = true ;
    ioList.addObject ("!") ;
    ioList.addObject ("&") ;
    ioList.addObject ("(") ;
    ioList.addObject (")") ;
    ioList.addObject ("*") ;
    ioList.addObject ("+") ;
    ioList.addObject (",") ;
    ioList.addObject ("/") ;
    ioList.addObject (":") ;
    ioList.addObject ("<") ;
    ioList.addObject (">") ;
    ioList.addObject ("\?") ;
    ioList.addObject ("@") ;
    ioList.addObject ("[") ;
    ioList.addObject ("]") ;
    ioList.addObject ("^") ;
    ioList.addObject ("{") ;
    ioList.addObject ("|") ;
    ioList.addObject ("}") ;
    ioList.addObject ("~") ;
    ioList.addObject ("!=") ;
    ioList.addObject ("&=") ;
    ioList.addObject ("*=") ;
    ioList.addObject ("+=") ;
    ioList.addObject ("-=") ;
    ioList.addObject ("->") ;
    ioList.addObject ("/=") ;
    ioList.addObject ("::") ;
    ioList.addObject (":=") ;
    ioList.addObject ("<-") ;
    ioList.addObject ("<<") ;
    ioList.addObject ("<=") ;
    ioList.addObject ("==") ;
    ioList.addObject (">=") ;
    ioList.addObject (">>") ;
    ioList.addObject ("@!") ;
    ioList.addObject ("@(") ;
    ioList.addObject ("@[") ;
    ioList.addObject ("@{") ;
    ioList.addObject ("[!") ;
    ioList.addObject ("^=") ;
    ioList.addObject ("|=") ;
    ioList.addObject ("<<=") ;
    ioList.addObject (">>=") ;
    ioList.addObject ("mod=") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "gtl_scanner:goilTemplateKeyWordList") {
    ioFound = true ;
    ioList.addObject ("by") ;
    ioList.addObject ("do") ;
    ioList.addObject ("if") ;
    ioList.addObject ("in") ;
    ioList.addObject ("no") ;
    ioList.addObject ("or") ;
    ioList.addObject ("to") ;
    ioList.addObject ("up") ;
    ioList.addObject ("end") ;
    ioList.addObject ("for") ;
    ioList.addObject ("let") ;
    ioList.addObject ("mod") ;
    ioList.addObject ("not") ;
    ioList.addObject ("tab") ;
    ioList.addObject ("yes") ;
    ioList.addObject ("down") ;
    ioList.addObject ("else") ;
    ioList.addObject ("from") ;
    ioList.addObject ("func") ;
    ioList.addObject ("here") ;
    ioList.addObject ("loop") ;
    ioList.addObject ("sort") ;
    ioList.addObject ("step") ;
    ioList.addObject ("then") ;
    ioList.addObject ("true") ;
    ioList.addObject ("after") ;
    ioList.addObject ("elsif") ;
    ioList.addObject ("error") ;
    ioList.addObject ("false") ;
    ioList.addObject ("input") ;
    ioList.addObject ("mapof") ;
    ioList.addObject ("print") ;
    ioList.addObject ("unlet") ;
    ioList.addObject ("while") ;
    ioList.addObject ("write") ;
    ioList.addObject ("before") ;
    ioList.addObject ("exists") ;
    ioList.addObject ("getter") ;
    ioList.addObject ("import") ;
    ioList.addObject ("listof") ;
    ioList.addObject ("repeat") ;
    ioList.addObject ("setter") ;
    ioList.addObject ("typeof") ;
    ioList.addObject ("between") ;
    ioList.addObject ("default") ;
    ioList.addObject ("display") ;
    ioList.addObject ("foreach") ;
    ioList.addObject ("println") ;
    ioList.addObject ("warning") ;
    ioList.addObject ("emptymap") ;
    ioList.addObject ("template") ;
    ioList.addObject ("emptylist") ;
    ioList.addObject ("libraries") ;
    ioList.addObject ("variables") ;
    ioList.addObject ("executable") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static cLexiqueIntrospection lexiqueIntrospection_gtl_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_gtl_5F_scanner, getKeywordsForIdentifier_gtl_5F_scanner) ;

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_Lexique_gtl_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [112] = {0,
    0 /* gtl_scanner_1_identifier */,
    0 /* gtl_scanner_1_literal_5F_enum */,
    5 /* gtl_scanner_1_literal_5F_double */,
    4 /* gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint */,
    2 /* gtl_scanner_1__2D_ */,
    2 /* gtl_scanner_1__2E_ */,
    2 /* gtl_scanner_1__2E__3D_ */,
    2 /* gtl_scanner_1__2E__2E__2E_ */,
    8 /* gtl_scanner_1_literal_5F_char */,
    6 /* gtl_scanner_1_string */,
    7 /* gtl_scanner_1_comment */,
    1 /* gtl_scanner_1_after */,
    1 /* gtl_scanner_1_before */,
    1 /* gtl_scanner_1_between */,
    1 /* gtl_scanner_1_by */,
    1 /* gtl_scanner_1_default */,
    1 /* gtl_scanner_1_display */,
    1 /* gtl_scanner_1_do */,
    1 /* gtl_scanner_1_down */,
    1 /* gtl_scanner_1_else */,
    1 /* gtl_scanner_1_elsif */,
    1 /* gtl_scanner_1_emptylist */,
    1 /* gtl_scanner_1_emptymap */,
    1 /* gtl_scanner_1_end */,
    1 /* gtl_scanner_1_error */,
    1 /* gtl_scanner_1_exists */,
    1 /* gtl_scanner_1_false */,
    1 /* gtl_scanner_1_for */,
    1 /* gtl_scanner_1_foreach */,
    1 /* gtl_scanner_1_from */,
    1 /* gtl_scanner_1_func */,
    1 /* gtl_scanner_1_here */,
    1 /* gtl_scanner_1_if */,
    1 /* gtl_scanner_1_in */,
    1 /* gtl_scanner_1_import */,
    1 /* gtl_scanner_1_listof */,
    1 /* gtl_scanner_1_let */,
    1 /* gtl_scanner_1_loop */,
    1 /* gtl_scanner_1_mapof */,
    1 /* gtl_scanner_1_mod */,
    1 /* gtl_scanner_1_no */,
    1 /* gtl_scanner_1_not */,
    1 /* gtl_scanner_1_or */,
    1 /* gtl_scanner_1_print */,
    1 /* gtl_scanner_1_println */,
    1 /* gtl_scanner_1_repeat */,
    1 /* gtl_scanner_1_sort */,
    1 /* gtl_scanner_1_step */,
    1 /* gtl_scanner_1_tab */,
    1 /* gtl_scanner_1_template */,
    1 /* gtl_scanner_1_then */,
    1 /* gtl_scanner_1_to */,
    1 /* gtl_scanner_1_true */,
    1 /* gtl_scanner_1_typeof */,
    1 /* gtl_scanner_1_up */,
    1 /* gtl_scanner_1_yes */,
    1 /* gtl_scanner_1_warning */,
    1 /* gtl_scanner_1_while */,
    1 /* gtl_scanner_1_write */,
    1 /* gtl_scanner_1_executable */,
    1 /* gtl_scanner_1_variables */,
    1 /* gtl_scanner_1_getter */,
    1 /* gtl_scanner_1_unlet */,
    1 /* gtl_scanner_1_setter */,
    1 /* gtl_scanner_1_libraries */,
    1 /* gtl_scanner_1_input */,
    2 /* gtl_scanner_1__2A_ */,
    2 /* gtl_scanner_1__7C_ */,
    2 /* gtl_scanner_1__2C_ */,
    2 /* gtl_scanner_1__2B_ */,
    2 /* gtl_scanner_1__3A__3A_ */,
    2 /* gtl_scanner_1__3E_ */,
    2 /* gtl_scanner_1__3A_ */,
    2 /* gtl_scanner_1__28_ */,
    2 /* gtl_scanner_1__29_ */,
    2 /* gtl_scanner_1__2D__3E_ */,
    2 /* gtl_scanner_1__3F_ */,
    2 /* gtl_scanner_1__3D__3D_ */,
    2 /* gtl_scanner_1__21_ */,
    2 /* gtl_scanner_1__3A__3D_ */,
    2 /* gtl_scanner_1__5B_ */,
    2 /* gtl_scanner_1__5D_ */,
    2 /* gtl_scanner_1__2B__3D_ */,
    2 /* gtl_scanner_1__2D__3D_ */,
    2 /* gtl_scanner_1__2F_ */,
    2 /* gtl_scanner_1__21__3D_ */,
    2 /* gtl_scanner_1__3E__3D_ */,
    2 /* gtl_scanner_1__26_ */,
    2 /* gtl_scanner_1__3C__3D_ */,
    2 /* gtl_scanner_1__7B_ */,
    2 /* gtl_scanner_1__7D_ */,
    2 /* gtl_scanner_1__3C_ */,
    2 /* gtl_scanner_1__5E_ */,
    2 /* gtl_scanner_1__3E__3E_ */,
    2 /* gtl_scanner_1__7E_ */,
    2 /* gtl_scanner_1__3C__2D_ */,
    2 /* gtl_scanner_1__3C__3C_ */,
    2 /* gtl_scanner_1__40_ */,
    2 /* gtl_scanner_1__2A__3D_ */,
    2 /* gtl_scanner_1__2F__3D_ */,
    2 /* gtl_scanner_1__26__3D_ */,
    2 /* gtl_scanner_1__7C__3D_ */,
    2 /* gtl_scanner_1__3C__3C__3D_ */,
    2 /* gtl_scanner_1__3E__3E__3D_ */,
    2 /* gtl_scanner_1_mod_3D_ */,
    2 /* gtl_scanner_1__5E__3D_ */,
    2 /* gtl_scanner_1__40__5B_ */,
    2 /* gtl_scanner_1__40__28_ */,
    2 /* gtl_scanner_1__40__7B_ */,
    2 /* gtl_scanner_1__5B__21_ */,
    2 /* gtl_scanner_1__40__21_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                                            *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 9) {
    static const char * kStyleArray [9] = {
      "",
      "keywordsStyle",
      "delimitersStyle",
      "nonTerminalStyle",
      "integerStyle",
      "floatCsts",
      "stringStyle",
      "commentStyle",
      "characterStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                  C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_relation_5F_term_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      GALGAS_location var_opLocation_1099 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      GALGAS_gtlExpression var_rightSon_1156 ;
      nt_gtl_5F_relation_5F_term_ (var_rightSon_1156, inCompiler) ;
      outArgument_expression = GALGAS_gtlOrExpression::constructor_new (var_opLocation_1099, outArgument_expression, var_rightSon_1156  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 41)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
      GALGAS_location var_opLocation_1269 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
      GALGAS_gtlExpression var_rightSon_1326 ;
      nt_gtl_5F_relation_5F_term_ (var_rightSon_1326, inCompiler) ;
      outArgument_expression = GALGAS_gtlXorExpression::constructor_new (var_opLocation_1269, outArgument_expression, var_rightSon_1326  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 45)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
      nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                        C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_relation_5F_factor_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_1 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      GALGAS_location var_opLocation_1794 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      GALGAS_gtlExpression var_rightSon_1853 ;
      nt_gtl_5F_relation_5F_factor_ (var_rightSon_1853, inCompiler) ;
      outArgument_expression = GALGAS_gtlAndExpression::constructor_new (var_opLocation_1794, outArgument_expression, var_rightSon_1853  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 61)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_1 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      nt_gtl_5F_relation_5F_factor_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                          C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_simple_5F_expression_ (outArgument_expression, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3D__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    GALGAS_location var_opLocation_2323 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    GALGAS_gtlExpression var_rightSon_2384 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2384, inCompiler) ;
    outArgument_expression = GALGAS_gtlEqualExpression::constructor_new (var_opLocation_2323, outArgument_expression, var_rightSon_2384  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 77)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    GALGAS_location var_opLocation_2508 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    GALGAS_gtlExpression var_rightSon_2569 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2569, inCompiler) ;
    outArgument_expression = GALGAS_gtlNotEqualExpression::constructor_new (var_opLocation_2508, outArgument_expression, var_rightSon_2569  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 83)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    GALGAS_location var_opLocation_2696 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    GALGAS_gtlExpression var_rightSon_2757 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2757, inCompiler) ;
    outArgument_expression = GALGAS_gtlLowerOrEqualExpression::constructor_new (var_opLocation_2696, outArgument_expression, var_rightSon_2757  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 89)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    GALGAS_location var_opLocation_2888 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    GALGAS_gtlExpression var_rightSon_2949 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2949, inCompiler) ;
    outArgument_expression = GALGAS_gtlGreaterOrEqualExpression::constructor_new (var_opLocation_2888, outArgument_expression, var_rightSon_2949  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 95)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    GALGAS_location var_opLocation_3081 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    GALGAS_gtlExpression var_rightSon_3142 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3142, inCompiler) ;
    outArgument_expression = GALGAS_gtlGreaterThanExpression::constructor_new (var_opLocation_3081, outArgument_expression, var_rightSon_3142  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 101)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    GALGAS_location var_opLocation_3271 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    GALGAS_gtlExpression var_rightSon_3332 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3332, inCompiler) ;
    outArgument_expression = GALGAS_gtlLowerThanExpression::constructor_new (var_opLocation_3271, outArgument_expression, var_rightSon_3332  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 107)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3D__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                            C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_term_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      GALGAS_location var_opLocation_3811 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      GALGAS_gtlExpression var_rightSon_3859 ;
      nt_gtl_5F_term_ (var_rightSon_3859, inCompiler) ;
      outArgument_expression = GALGAS_gtlShiftLeftExpression::constructor_new (var_opLocation_3811, outArgument_expression, var_rightSon_3859  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 125)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      GALGAS_location var_opLocation_3991 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      GALGAS_gtlExpression var_rightSon_4039 ;
      nt_gtl_5F_term_ (var_rightSon_4039, inCompiler) ;
      outArgument_expression = GALGAS_gtlShiftRightExpression::constructor_new (var_opLocation_3991, outArgument_expression, var_rightSon_4039  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 131)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      GALGAS_location var_opLocation_4171 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      GALGAS_gtlExpression var_rightSon_4219 ;
      nt_gtl_5F_term_ (var_rightSon_4219, inCompiler) ;
      outArgument_expression = GALGAS_gtlAddExpression::constructor_new (var_opLocation_4171, outArgument_expression, var_rightSon_4219  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 137)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      GALGAS_location var_opLocation_4344 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      const enumGalgasBool test_1 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        appendFixItActions (fixItArray2, kFixItReplace, GALGAS_string ("+")) ;
        inCompiler->emitSemanticWarning (var_opLocation_4344, GALGAS_string ("'.' operator is deprecated"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 143)) ;
      }
      GALGAS_gtlExpression var_rightSon_4532 ;
      nt_gtl_5F_term_ (var_rightSon_4532, inCompiler) ;
      outArgument_expression = GALGAS_gtlAddExpression::constructor_new (var_opLocation_4344, outArgument_expression, var_rightSon_4532  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 146)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
      GALGAS_location var_opLocation_4657 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
      GALGAS_gtlExpression var_rightSon_4705 ;
      nt_gtl_5F_term_ (var_rightSon_4705, inCompiler) ;
      outArgument_expression = GALGAS_gtlSubstractExpression::constructor_new (var_opLocation_4657, outArgument_expression, var_rightSon_4705  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 152)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_term_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                            C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_factor_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      GALGAS_location var_opLocation_5172 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      GALGAS_gtlExpression var_rightSon_5222 ;
      nt_gtl_5F_factor_ (var_rightSon_5222, inCompiler) ;
      outArgument_expression = GALGAS_gtlMultiplyExpression::constructor_new (var_opLocation_5172, outArgument_expression, var_rightSon_5222  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 170)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      GALGAS_location var_opLocation_5352 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      GALGAS_gtlExpression var_rightSon_5402 ;
      nt_gtl_5F_factor_ (var_rightSon_5402, inCompiler) ;
      outArgument_expression = GALGAS_gtlDivideExpression::constructor_new (var_opLocation_5352, outArgument_expression, var_rightSon_5402  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 176)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
      GALGAS_location var_opLocation_5532 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
      GALGAS_gtlExpression var_rightSon_5582 ;
      nt_gtl_5F_factor_ (var_rightSon_5582, inCompiler) ;
      outArgument_expression = GALGAS_gtlModulusExpression::constructor_new (var_opLocation_5532, outArgument_expression, var_rightSon_5582  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 182)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  GALGAS_location var_opLocation_6002 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  GALGAS_gtlExpression var_factorExpression_6062 ;
  nt_gtl_5F_expression_ (var_factorExpression_6062, inCompiler) ;
  outArgument_expression = GALGAS_gtlParenthesizedExpression::constructor_new (var_opLocation_6002, var_factorExpression_6062  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 197)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 201)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 201)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  GALGAS_location var_opLocation_6484 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  GALGAS_gtlExpression var_notExpression_6537 ;
  nt_gtl_5F_factor_ (var_notExpression_6537, inCompiler) ;
  outArgument_expression = GALGAS_gtlNotExpression::constructor_new (var_opLocation_6484, var_notExpression_6537  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 213)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  GALGAS_location var_opLocation_6928 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  GALGAS_gtlExpression var_notExpression_6981 ;
  nt_gtl_5F_factor_ (var_notExpression_6981, inCompiler) ;
  outArgument_expression = GALGAS_gtlNotExpression::constructor_new (var_opLocation_6928, var_notExpression_6981  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 225)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  GALGAS_location var_opLocation_7372 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  GALGAS_gtlExpression var_minusExpression_7427 ;
  nt_gtl_5F_factor_ (var_minusExpression_7427, inCompiler) ;
  outArgument_expression = GALGAS_gtlMinusExpression::constructor_new (var_opLocation_7372, var_minusExpression_7427  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 237)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  GALGAS_location var_opLocation_7822 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  GALGAS_gtlExpression var_plusExpression_7876 ;
  nt_gtl_5F_factor_ (var_plusExpression_7876, inCompiler) ;
  outArgument_expression = GALGAS_gtlPlusExpression::constructor_new (var_opLocation_7822, var_plusExpression_7876  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 249)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_yes) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  GALGAS_location var_opLocation_8271 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (var_opLocation_8271, GALGAS_gtlBool::constructor_new (var_opLocation_8271, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 261)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 261))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 260)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_yes) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_no) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 272)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 273)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_no) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 272)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lbigint var_literalInteger_9142 = inCompiler->synthetizedAttribute_intValue () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 285)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), var_literalInteger_9142.getter_bigint (SOURCE_FILE ("gtl_expression_parser.galgas", 287))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 286)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 285)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_ldouble var_literalFloat_9597 = inCompiler->synthetizedAttribute_floatValue () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 298)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), GALGAS_gtlFloat::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), var_literalFloat_9597.getter_double (SOURCE_FILE ("gtl_expression_parser.galgas", 300))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 299)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 298)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lstring var_literalString_10045 = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 311)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), var_literalString_10045.getter_string (SOURCE_FILE ("gtl_expression_parser.galgas", 313))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 312)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 311)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lchar var_literalChar_10495 = inCompiler->synthetizedAttribute_charValue () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 324)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), GALGAS_gtlChar::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), var_literalChar_10495.getter_char (SOURCE_FILE ("gtl_expression_parser.galgas", 326))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 325)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 324)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 338)) ;
  GALGAS_gtlExpression var_target_11029 ;
  nt_gtl_5F_expression_ (var_target_11029, inCompiler) ;
  GALGAS_lstring var_getterName_11069 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 340)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("stringByCapitalizingFirstCharacter").objectCompare (var_getterName_11069.getter_string (SOURCE_FILE ("gtl_expression_parser.galgas", 342)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      appendFixItActions (fixItArray2, kFixItReplace, GALGAS_string ("capitalized")) ;
      inCompiler->emitSemanticWarning (var_getterName_11069.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 343)), GALGAS_string ("stringByCapitalizingFirstCharacter is deprecated"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 343)) ;
    }
  }
  GALGAS_gtlExpressionList var_argumentList_11350 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 347)) ;
  switch (select_gtl_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 350)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      GALGAS_gtlExpression var_argument_11444 ;
      nt_gtl_5F_expression_ (var_argument_11444, inCompiler) ;
      var_argumentList_11350.addAssign_operation (var_argument_11444  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 353)) ;
      switch (select_gtl_5F_expression_5F_parser_6 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 355)) ;
      } break ;
      default:
        repeatFlag_3 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 358)) ;
  outArgument_expression = GALGAS_gtlGetterCallExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 360)), var_target_11029, var_getterName_11069, var_argumentList_11350  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 359)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 338)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 340)) ;
  switch (select_gtl_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 350)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_6 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 355)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 358)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_gtlVarPath var_path_11796 ;
  nt_gtl_5F_variable_ (var_path_11796, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
    outArgument_expression = GALGAS_gtlVarRef::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 374)), var_path_11796  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 374)) ;
  } break ;
  case 2: {
    const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_path_11796.getter_length (SOURCE_FILE ("gtl_expression_parser.galgas", 376)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 377)), GALGAS_string ("illegal function name"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 377)) ;
    }
    GALGAS_gtlExpressionList var_functionArguments_11982 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 379)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_2 = true ;
      while (repeatFlag_2) {
        GALGAS_gtlExpression var_expression_12079 ;
        nt_gtl_5F_expression_ (var_expression_12079, inCompiler) ;
        var_functionArguments_11982.addAssign_operation (var_expression_12079  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 384)) ;
        switch (select_gtl_5F_expression_5F_parser_9 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 386)) ;
        } break ;
        default:
          repeatFlag_2 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 389)) ;
    GALGAS_lstring var_functionName_12199 = extensionGetter_pathAsFunctionName (var_path_11796, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 390)) ;
    outArgument_expression = GALGAS_gtlFunctionCallExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 392)), var_functionName_12199, var_functionArguments_11982  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 391)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_parse (inCompiler) ;
        switch (select_gtl_5F_expression_5F_parser_9 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 386)) ;
        } break ;
        default:
          repeatFlag_0 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 389)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 404)) ;
  GALGAS_gtlVarPath var_path_12529 ;
  nt_gtl_5F_variable_ (var_path_12529, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_default) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 407)) ;
    GALGAS_gtlExpression var_defaultExpression_12615 ;
    nt_gtl_5F_expression_ (var_defaultExpression_12615, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 409)) ;
    outArgument_expression = GALGAS_gtlExistsDefaultExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 411)), var_path_12529, var_defaultExpression_12615  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 410)) ;
  } break ;
  case 2: {
    outArgument_expression = GALGAS_gtlExistsExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 414)), var_path_12529  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 414)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 404)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_default) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 407)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 409)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_typeof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 423)) ;
  GALGAS_gtlVarPath var_path_12970 ;
  nt_gtl_5F_variable_ (var_path_12970, inCompiler) ;
  outArgument_expression = GALGAS_gtlTypeOfExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 424)), var_path_12970  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 424)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_typeof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 423)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_true) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 432)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 434)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 436)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 437)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 435))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 433)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_true) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 432)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_false) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 448)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 450)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 452)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 453)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 451))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 449)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_false) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 448)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lstring var_enumValue_13736 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 464)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 466)), GALGAS_gtlEnum::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 468)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 469)), var_enumValue_13736.getter_string (SOURCE_FILE ("gtl_expression_parser.galgas", 470))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 467))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 465)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 464)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  GALGAS_lstring var_typeName_14040 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  GALGAS_string var_name_14055 = var_typeName_14040.getter_string (SOURCE_FILE ("gtl_expression_parser.galgas", 481)) ;
  GALGAS_gtlType var_type_14091 ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("int"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 484)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 484)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 484)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("float"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 486)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 486)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 486)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("string"))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 488)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 488)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 488)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 490)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 490)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 490)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
          if (kBoolTrue == test_4) {
            var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 492)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 492)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 492)) ;
          }else if (kBoolFalse == test_4) {
            const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("list"))).boolEnum () ;
            if (kBoolTrue == test_5) {
              var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 494)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 494)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlList)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 494)) ;
            }else if (kBoolFalse == test_5) {
              const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("map"))).boolEnum () ;
              if (kBoolTrue == test_6) {
                var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 496)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 496)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 496)) ;
              }else if (kBoolFalse == test_6) {
                const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                if (kBoolTrue == test_7) {
                  var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 498)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 498)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 498)) ;
                }else if (kBoolFalse == test_7) {
                  const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 500)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 500)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlType)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 500)) ;
                  }else if (kBoolFalse == test_8) {
                    const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 502)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 502)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 502)) ;
                    }else if (kBoolFalse == test_9) {
                      const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("char"))).boolEnum () ;
                      if (kBoolTrue == test_10) {
                        var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 504)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 504)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 504)) ;
                      }else if (kBoolFalse == test_10) {
                        const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                        if (kBoolTrue == test_11) {
                          var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 506)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 506)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 506)) ;
                        }else if (kBoolFalse == test_11) {
                          TC_Array <C_FixItDescription> fixItArray12 ;
                          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)), var_name_14055.add_operation (GALGAS_string (" does not name a type"), inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)), fixItArray12  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)) ;
                          var_type_14091.drop () ; // Release error dropped variable
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 509)), var_type_14091  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 509)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptylist) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 517)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("@( )")) ;
    inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 519)), GALGAS_string ("emptylist is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 519)) ;
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 522)), GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 524)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 525)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 526))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 523))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 521)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptylist) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 517)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptymap) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 536)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("@[ ]")) ;
    inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 538)), GALGAS_string ("emptymap is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 538)) ;
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 541)), GALGAS_gtlMap::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 543)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 544)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 545))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 542))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 540)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptymap) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 536)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mapof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 555)) ;
  GALGAS_gtlExpression var_data_16406 ;
  nt_gtl_5F_expression_ (var_data_16406, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 558)) ;
    GALGAS_lstring var_key_16459 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 559)) ;
    outArgument_expression = GALGAS_gtlMapOfListExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 561)), var_data_16406, var_key_16459  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 560)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 566)) ;
    outArgument_expression = GALGAS_gtlMapOfStructExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 568)), var_data_16406  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 567)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mapof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 555)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 558)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 559)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 566)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_listof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 579)) ;
  GALGAS_gtlExpression var_data_16839 ;
  nt_gtl_5F_expression_ (var_data_16839, inCompiler) ;
  outArgument_expression = GALGAS_gtlListOfExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 581)), var_data_16839  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 581)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 582)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_listof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 579)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 582)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 590)) ;
  GALGAS_gtlExpressionList var_expressionList_17081 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 591)) ;
  switch (select_gtl_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_listItem_17162 ;
      nt_gtl_5F_expression_ (var_listItem_17162, inCompiler) ;
      var_expressionList_17081.addAssign_operation (var_listItem_17162  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 595)) ;
      switch (select_gtl_5F_expression_5F_parser_13 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 596)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 600)) ;
  outArgument_expression = GALGAS_gtlLiteralListExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 601)), var_expressionList_17081  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 601)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 590)) ;
  switch (select_gtl_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_13 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 596)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 600)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 609)) ;
  GALGAS_gtlExpressionMap var_expressionMap_17482 = GALGAS_gtlExpressionMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 610)) ;
  switch (select_gtl_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_key_17548 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 614)) ;
      GALGAS_gtlExpression var_mapItem_17605 ;
      nt_gtl_5F_expression_ (var_mapItem_17605, inCompiler) ;
      {
      var_expressionMap_17482.setter_put (var_key_17548, var_mapItem_17605, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 616)) ;
      }
      switch (select_gtl_5F_expression_5F_parser_15 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 617)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 621)) ;
  outArgument_expression = GALGAS_gtlLiteralMapExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 622)), var_expressionMap_17482  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 622)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 609)) ;
  switch (select_gtl_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 614)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_15 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 617)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 621)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__7B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 630)) ;
  GALGAS_gtlExpressionMap var_expressionMap_17931 = GALGAS_gtlExpressionMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 631)) ;
  switch (select_gtl_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_fieldName_18006 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 635)) ;
      GALGAS_gtlExpression var_structField_18067 ;
      nt_gtl_5F_expression_ (var_structField_18067, inCompiler) ;
      {
      var_expressionMap_17931.setter_put (var_fieldName_18006, var_structField_18067, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 637)) ;
      }
      switch (select_gtl_5F_expression_5F_parser_17 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 638)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 642)) ;
  outArgument_expression = GALGAS_gtlLiteralStructExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 643)), var_expressionMap_17931  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 643)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__7B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 630)) ;
  switch (select_gtl_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 635)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_17 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 638)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 642)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__21_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 651)) ;
  GALGAS_gtlExpressionList var_expressionList_18408 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 652)) ;
  switch (select_gtl_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_setElement_18491 ;
      nt_gtl_5F_expression_ (var_setElement_18491, inCompiler) ;
      var_expressionList_18408.addAssign_operation (var_setElement_18491  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 656)) ;
      switch (select_gtl_5F_expression_5F_parser_19 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 657)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 661)) ;
  outArgument_expression = GALGAS_gtlLiteralSetExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 662)), var_expressionList_18408  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 662)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__21_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 651)) ;
  switch (select_gtl_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_19 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 657)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 661)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_ (GALGAS_gtlVarPath & outArgument_path,
                                                                                                 C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_path.drop () ; // Release 'out' argument
  outArgument_path = GALGAS_gtlVarPath::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 670)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_lstring var_variableName_18837 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 672)) ;
    switch (select_gtl_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 674)) ;
      GALGAS_gtlExpression var_expression_18912 ;
      nt_gtl_5F_expression_ (var_expression_18912, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 676)) ;
      outArgument_path.addAssign_operation (GALGAS_gtlVarItemCollection::constructor_new (var_variableName_18837, var_expression_18912  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 677))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 677)) ;
      switch (select_gtl_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 679)) ;
        GALGAS_gtlExpression var_expression_19074 ;
        nt_gtl_5F_expression_ (var_expression_19074, inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 681)) ;
        outArgument_path.addAssign_operation (GALGAS_gtlVarItemSubCollection::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 682)), var_expression_19074  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 682))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 682)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          switch (select_gtl_5F_expression_5F_parser_23 (inCompiler)) {
          case 2: {
            inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 685)) ;
            GALGAS_gtlExpression var_expression_19256 ;
            nt_gtl_5F_expression_ (var_expression_19256, inCompiler) ;
            inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 687)) ;
            outArgument_path.addAssign_operation (GALGAS_gtlVarItemSubCollection::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 688)), var_expression_19256  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 688))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 688)) ;
          } break ;
          default:
            repeatFlag_1 = false ;
            break ;
          }
        }
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
    } break ;
    case 2: {
      outArgument_path.addAssign_operation (GALGAS_gtlVarItemField::constructor_new (var_variableName_18837  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 693))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 693)) ;
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_expression_5F_parser_20 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 696)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 672)) ;
    switch (select_gtl_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 674)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 676)) ;
      switch (select_gtl_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 679)) ;
        nt_gtl_5F_expression_parse (inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 681)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          switch (select_gtl_5F_expression_5F_parser_23 (inCompiler)) {
          case 2: {
            inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 685)) ;
            nt_gtl_5F_expression_parse (inCompiler) ;
            inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 687)) ;
          } break ;
          default:
            repeatFlag_1 = false ;
            break ;
          }
        }
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_expression_5F_parser_20 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 696)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_ (GALGAS_gtlVarPath & outArgument_path,
                                                                                                               GALGAS_bool & outArgument_hereInstead,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_path.drop () ; // Release 'out' argument
  outArgument_hereInstead.drop () ; // Release 'out' argument
  switch (select_gtl_5F_expression_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
    outArgument_path = GALGAS_gtlVarPath::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
    outArgument_hereInstead = GALGAS_bool (true) ;
  } break ;
  case 2: {
    nt_gtl_5F_variable_ (outArgument_path, inCompiler) ;
    outArgument_hereInstead = GALGAS_bool (false) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_expression_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
  } break ;
  case 2: {
    nt_gtl_5F_variable_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_ (GALGAS_gtlArgumentList & outArgument_arguments,
                                                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_arguments.drop () ; // Release 'out' argument
  outArgument_arguments = GALGAS_gtlArgumentList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 719)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 720)) ;
  switch (select_gtl_5F_expression_5F_parser_25 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_argumentName_19978 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 723)) ;
      switch (select_gtl_5F_expression_5F_parser_27 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        GALGAS_lstring var_typeName_20043 = inCompiler->synthetizedAttribute_tokenString () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        outArgument_arguments.addAssign_operation (GALGAS_bool (true), extensionGetter_gtlType (var_typeName_20043, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 726)), var_argumentName_19978  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 726)) ;
      } break ;
      case 2: {
        outArgument_arguments.addAssign_operation (GALGAS_bool (false), GALGAS_type (& kTypeDescriptor_GALGAS_gtlData), var_argumentName_19978  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 728)) ;
      } break ;
      default:
        break ;
      }
      switch (select_gtl_5F_expression_5F_parser_26 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 730)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 733)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 720)) ;
  switch (select_gtl_5F_expression_5F_parser_25 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 723)) ;
      switch (select_gtl_5F_expression_5F_parser_27 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_gtl_5F_expression_5F_parser_26 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 730)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 733)) ;
  inCompiler->resetTemplateString () ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_ (GALGAS_gtlContext inArgument_context,
                                                                           GALGAS_library & ioArgument_lib,
                                                                           GALGAS_gtlInstructionList & outArgument_program,
                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_program.drop () ; // Release 'out' argument
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_ (inArgument_context, ioArgument_lib, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_gtl_5F_template_5F_instruction_5F_list_ (outArgument_program, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_ (GALGAS_gtlInstructionList & outArgument_instructionList,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instructionList.drop () ; // Release 'out' argument
  outArgument_instructionList = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 65)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_string var_templateString_1561 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 68)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_templateString_1561.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_instructionList.addAssign_operation (GALGAS_gtlTemplateStringInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 71)), var_templateString_1561  COMMA_SOURCE_FILE ("gtl_parser.galgas", 71))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 70)) ;
    }
    switch (select_gtl_5F_parser_1 (inCompiler)) {
    case 2: {
      GALGAS_gtlInstruction var_instruction_1805 ;
      nt_gtl_5F_template_5F_instruction_ (var_instruction_1805, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1805  COMMA_SOURCE_FILE ("gtl_parser.galgas", 75)) ;
    } break ;
    case 3: {
      GALGAS_gtlInstruction var_instruction_1907 ;
      nt_gtl_5F_simple_5F_instruction_ (var_instruction_1907, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1907  COMMA_SOURCE_FILE ("gtl_parser.galgas", 78)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_template_5F_instruction_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_simple_5F_instruction_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 88)) ;
  GALGAS_location var_where_2239 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 88)) ;
  GALGAS_gtlExpression var_expression_2293 ;
  nt_gtl_5F_expression_ (var_expression_2293, inCompiler) ;
  outArgument_instruction = GALGAS_gtlEmitInstruction::constructor_new (var_where_2239, var_expression_2293  COMMA_SOURCE_FILE ("gtl_parser.galgas", 91)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 88)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_bool var_isExecutable_2694 = GALGAS_bool (false) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) COMMA_SOURCE_FILE ("gtl_parser.galgas", 103)) ;
  GALGAS_location var_where_2728 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 103)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_parser.galgas", 103)) ;
  switch (select_gtl_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_executable) COMMA_SOURCE_FILE ("gtl_parser.galgas", 104)) ;
    var_isExecutable_2694 = GALGAS_bool (true) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  GALGAS_gtlExpression var_fileName_2834 ;
  nt_gtl_5F_expression_ (var_fileName_2834, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 106)) ;
  GALGAS_gtlInstructionList var_instructionList_2911 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_2911, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 108)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) COMMA_SOURCE_FILE ("gtl_parser.galgas", 108)) ;
  outArgument_instruction = GALGAS_gtlWriteToInstruction::constructor_new (var_where_2728, var_fileName_2834, var_isExecutable_2694, var_instructionList_2911  COMMA_SOURCE_FILE ("gtl_parser.galgas", 110)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) COMMA_SOURCE_FILE ("gtl_parser.galgas", 103)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_parser.galgas", 103)) ;
  switch (select_gtl_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_executable) COMMA_SOURCE_FILE ("gtl_parser.galgas", 104)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 106)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 108)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) COMMA_SOURCE_FILE ("gtl_parser.galgas", 108)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_lstring var_prefix_3196 ;
  GALGAS_bool var_ifExists_3213 = GALGAS_bool (false) ;
  GALGAS_gtlInstructionList var_instructionList_3259 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 120)) ;
  GALGAS_gtlExpression var_fileName_3298 ;
  GALGAS_gtlExpressionList var_templateArguments_3337 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 122)) ;
  GALGAS_bool var_globalTemplate_3373 = GALGAS_bool (true) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) COMMA_SOURCE_FILE ("gtl_parser.galgas", 125)) ;
  GALGAS_location var_where_3412 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 125)) ;
  switch (select_gtl_5F_parser_3 (inCompiler)) {
  case 1: {
    var_globalTemplate_3373 = GALGAS_bool (false) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 128)) ;
    switch (select_gtl_5F_parser_4 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        GALGAS_gtlExpression var_expression_3540 ;
        nt_gtl_5F_expression_ (var_expression_3540, inCompiler) ;
        var_templateArguments_3337.addAssign_operation (var_expression_3540  COMMA_SOURCE_FILE ("gtl_parser.galgas", 132)) ;
        switch (select_gtl_5F_parser_5 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 134)) ;
        } break ;
        default:
          repeatFlag_0 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 137)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 141)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) COMMA_SOURCE_FILE ("gtl_parser.galgas", 141)) ;
    var_ifExists_3213 = GALGAS_bool (true) ;
    nt_gtl_5F_file_5F_name_ (var_fileName_3298, inCompiler) ;
    switch (select_gtl_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 145)) ;
      var_prefix_3196 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 145)) ;
    } break ;
    case 2: {
      var_prefix_3196 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 146))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 146)) ;
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_parser_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_or) COMMA_SOURCE_FILE ("gtl_parser.galgas", 148)) ;
      nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_3259, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 150)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) COMMA_SOURCE_FILE ("gtl_parser.galgas", 150)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_gtl_5F_file_5F_name_ (var_fileName_3298, inCompiler) ;
    switch (select_gtl_5F_parser_9 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 155)) ;
      var_prefix_3196 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 155)) ;
    } break ;
    case 2: {
      var_prefix_3196 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 156))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 156)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  outArgument_instruction = GALGAS_gtlTemplateInstruction::constructor_new (var_where_3412, var_prefix_3196, var_fileName_3298, var_ifExists_3213, var_globalTemplate_3373, var_templateArguments_3337, var_instructionList_3259  COMMA_SOURCE_FILE ("gtl_parser.galgas", 158)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) COMMA_SOURCE_FILE ("gtl_parser.galgas", 125)) ;
  switch (select_gtl_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 128)) ;
    switch (select_gtl_5F_parser_4 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_parse (inCompiler) ;
        switch (select_gtl_5F_parser_5 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 134)) ;
        } break ;
        default:
          repeatFlag_0 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 137)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 141)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) COMMA_SOURCE_FILE ("gtl_parser.galgas", 141)) ;
    nt_gtl_5F_file_5F_name_parse (inCompiler) ;
    switch (select_gtl_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 145)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 145)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_parser_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_or) COMMA_SOURCE_FILE ("gtl_parser.galgas", 148)) ;
      nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 150)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) COMMA_SOURCE_FILE ("gtl_parser.galgas", 150)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_gtl_5F_file_5F_name_parse (inCompiler) ;
    switch (select_gtl_5F_parser_9 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 155)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 155)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3F_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 172)) ;
  GALGAS_location var_where_4391 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 172)) ;
  GALGAS_gtlVarPath var_columnConstantName_4452 ;
  nt_gtl_5F_variable_ (var_columnConstantName_4452, inCompiler) ;
  outArgument_instruction = GALGAS_gtlGetColumnInstruction::constructor_new (var_where_4391, var_columnConstantName_4452  COMMA_SOURCE_FILE ("gtl_parser.galgas", 175)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3F_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 172)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlThenElsifStatementList var_thenElsifList_4726 = GALGAS_gtlThenElsifStatementList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 183)) ;
  GALGAS_gtlInstructionList var_elseList_4770 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 184)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 186)) ;
  GALGAS_location var_where_4809 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 186)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlExpression var_condition_4873 ;
    nt_gtl_5F_expression_ (var_condition_4873, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) COMMA_SOURCE_FILE ("gtl_parser.galgas", 189)) ;
    GALGAS_gtlInstructionList var_instructionList_4957 ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_4957, inCompiler) ;
    var_thenElsifList_4726.addAssign_operation (var_condition_4873, var_instructionList_4957  COMMA_SOURCE_FILE ("gtl_parser.galgas", 192)) ;
    switch (select_gtl_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) COMMA_SOURCE_FILE ("gtl_parser.galgas", 194)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) COMMA_SOURCE_FILE ("gtl_parser.galgas", 198)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_elseList_4770, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 202)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 203)) ;
  outArgument_instruction = GALGAS_gtlIfStatementInstruction::constructor_new (var_where_4809, var_thenElsifList_4726, var_elseList_4770  COMMA_SOURCE_FILE ("gtl_parser.galgas", 205)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 186)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) COMMA_SOURCE_FILE ("gtl_parser.galgas", 189)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
    switch (select_gtl_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) COMMA_SOURCE_FILE ("gtl_parser.galgas", 194)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) COMMA_SOURCE_FILE ("gtl_parser.galgas", 198)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 202)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 203)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_5413 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 213)) ;
  GALGAS_gtlInstructionList var_doList_5455 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 214)) ;
  GALGAS_gtlInstructionList var_betweenList_5502 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 215)) ;
  GALGAS_gtlInstructionList var_afterList_5547 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 216)) ;
  GALGAS_lstring var_indexName_5581 ;
  GALGAS_lstring var_variableName_5605 ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_parser.galgas", 220)) ;
  GALGAS_location var_where_5636 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 220)) ;
  GALGAS_lstring var_keyName_5681 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 221)) ;
  switch (select_gtl_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 223)) ;
    var_variableName_5605 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 223)) ;
  } break ;
  case 2: {
    var_variableName_5605 = var_keyName_5681 ;
    var_keyName_5681 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), var_where_5636  COMMA_SOURCE_FILE ("gtl_parser.galgas", 226)) ;
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 229)) ;
    var_indexName_5581 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 229)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 229)) ;
  } break ;
  case 2: {
    var_indexName_5581 = GALGAS_lstring::constructor_new (GALGAS_string ("INDEX"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 231))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 231)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 233)) ;
  GALGAS_gtlExpression var_iterable_5945 ;
  nt_gtl_5F_expression_ (var_iterable_5945, inCompiler) ;
  switch (select_gtl_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_parser.galgas", 237)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_beforeList_5413, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 241)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_5455, inCompiler) ;
  switch (select_gtl_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 245)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_5502, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_parser.galgas", 250)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_afterList_5547, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 254)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_parser.galgas", 255)) ;
  outArgument_instruction = GALGAS_gtlForeachStatementInstruction::constructor_new (var_where_5636, var_keyName_5681, var_variableName_5605, var_indexName_5581, var_iterable_5945, var_beforeList_5413, var_betweenList_5502, var_afterList_5547, var_doList_5455  COMMA_SOURCE_FILE ("gtl_parser.galgas", 257)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_parser.galgas", 220)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 221)) ;
  switch (select_gtl_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 223)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 223)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 229)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 229)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 229)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 233)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_parser.galgas", 237)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 241)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 245)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_parser.galgas", 250)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 254)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_parser.galgas", 255)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_doList_6695 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 273)) ;
  GALGAS_gtlInstructionList var_betweenList_6742 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 274)) ;
  GALGAS_gtlExpressionList var_iterable_6786 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 275)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_parser.galgas", 277)) ;
  GALGAS_location var_where_6825 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 277)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("foreach var in @( expression, ..., expression )")) ;
    inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 279)), GALGAS_string ("for var in expression, ..., expression is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_parser.galgas", 279)) ;
  }
  GALGAS_lstring var_variableName_7082 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 282)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 283)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    GALGAS_gtlExpression var_expression_7146 ;
    nt_gtl_5F_expression_ (var_expression_7146, inCompiler) ;
    var_iterable_6786.addAssign_operation (var_expression_7146  COMMA_SOURCE_FILE ("gtl_parser.galgas", 286)) ;
    switch (select_gtl_5F_parser_17 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 288)) ;
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 291)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_6695, inCompiler) ;
  switch (select_gtl_5F_parser_18 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 295)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_6742, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 299)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_parser.galgas", 300)) ;
  outArgument_instruction = GALGAS_gtlForStatementInstruction::constructor_new (var_where_6825, var_variableName_7082, var_iterable_6786, var_betweenList_6742, var_doList_6695  COMMA_SOURCE_FILE ("gtl_parser.galgas", 302)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_parser.galgas", 277)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 282)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 283)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    switch (select_gtl_5F_parser_17 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 288)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 291)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_18 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 295)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 299)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_parser.galgas", 300)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_7672 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 310)) ;
  GALGAS_gtlInstructionList var_betweenList_7719 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 311)) ;
  GALGAS_gtlInstructionList var_afterList_7764 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 312)) ;
  GALGAS_sint_36__34_ var_direction_7797 = GALGAS_sint_36__34_ ((int64_t) 1LL) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_parser.galgas", 315)) ;
  GALGAS_location var_where_7831 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 315)) ;
  GALGAS_gtlExpression var_step_7862 = GALGAS_gtlTerminal::constructor_new (var_where_7831, GALGAS_gtlInt::constructor_new (var_where_7831, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 318)), GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 318))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 318))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 317)) ;
  GALGAS_lstring var_variableName_7987 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 321)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_parser.galgas", 322)) ;
  GALGAS_gtlExpression var_start_8037 ;
  nt_gtl_5F_expression_ (var_start_8037, inCompiler) ;
  switch (select_gtl_5F_parser_19 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) COMMA_SOURCE_FILE ("gtl_parser.galgas", 326)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) COMMA_SOURCE_FILE ("gtl_parser.galgas", 328)) ;
    var_direction_7797 = GALGAS_sint_36__34_ ((int64_t) 1LL).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 328)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_parser.galgas", 330)) ;
  GALGAS_gtlExpression var_stop_8147 ;
  nt_gtl_5F_expression_ (var_stop_8147, inCompiler) ;
  switch (select_gtl_5F_parser_20 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_parser.galgas", 333)) ;
    nt_gtl_5F_expression_ (var_step_7862, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_parser.galgas", 338)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_beforeList_7672, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 342)) ;
  GALGAS_gtlInstructionList var_doList_8383 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_8383, inCompiler) ;
  switch (select_gtl_5F_parser_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 346)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_7719, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_parser.galgas", 351)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_afterList_7764, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 355)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_parser.galgas", 356)) ;
  outArgument_instruction = GALGAS_gtlLoopStatementInstruction::constructor_new (var_where_7831, var_variableName_7987, var_start_8037, var_stop_8147, var_step_7862, var_direction_7797, var_beforeList_7672, var_betweenList_7719, var_afterList_7764, var_doList_8383  COMMA_SOURCE_FILE ("gtl_parser.galgas", 358)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_parser.galgas", 315)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 321)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_parser.galgas", 322)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_19 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) COMMA_SOURCE_FILE ("gtl_parser.galgas", 326)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) COMMA_SOURCE_FILE ("gtl_parser.galgas", 328)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_parser.galgas", 330)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_20 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_parser.galgas", 333)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_parser.galgas", 338)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 342)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 346)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_parser.galgas", 351)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 355)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_parser.galgas", 356)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                    C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlExpression var_limit_8929 ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_parser.galgas", 369)) ;
  GALGAS_location var_where_8959 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 369)) ;
  switch (select_gtl_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 371)) ;
    nt_gtl_5F_expression_ (var_limit_8929, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 373)) ;
  } break ;
  case 2: {
    var_limit_8929 = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 376)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 376)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 376)), GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_parser.galgas", 376)).getter_bigint (SOURCE_FILE ("gtl_parser.galgas", 376))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 376))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 375)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_gtlInstructionList var_continueList_9210 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_continueList_9210, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) COMMA_SOURCE_FILE ("gtl_parser.galgas", 380)) ;
  GALGAS_gtlExpression var_condition_9265 ;
  nt_gtl_5F_expression_ (var_condition_9265, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 382)) ;
  GALGAS_gtlInstructionList var_doList_9334 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_9334, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 384)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_parser.galgas", 385)) ;
  outArgument_instruction = GALGAS_gtlRepeatStatementInstruction::constructor_new (var_where_8959, var_limit_8929, var_condition_9265, var_continueList_9210, var_doList_9334  COMMA_SOURCE_FILE ("gtl_parser.galgas", 387)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_parser.galgas", 369)) ;
  switch (select_gtl_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 371)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 373)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) COMMA_SOURCE_FILE ("gtl_parser.galgas", 380)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 382)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 384)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_parser.galgas", 385)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                    C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_input) COMMA_SOURCE_FILE ("gtl_parser.galgas", 395)) ;
  GALGAS_location var_where_9636 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 395)) ;
  GALGAS_gtlArgumentList var_arguments_9694 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_9694, inCompiler) ;
  outArgument_instruction = GALGAS_gtlInputStatementInstruction::constructor_new (var_where_9636, var_arguments_9694  COMMA_SOURCE_FILE ("gtl_parser.galgas", 398)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_input) COMMA_SOURCE_FILE ("gtl_parser.galgas", 395)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_ (GALGAS_gtlExpression & outArgument_expression,
                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  switch (select_gtl_5F_parser_25 (inCompiler)) {
  case 1: {
    GALGAS_lstring var_fileName_9959 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 408)) ;
    outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 410)), GALGAS_gtlString::constructor_new (var_fileName_9959.getter_location (SOURCE_FILE ("gtl_parser.galgas", 411)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 411)), var_fileName_9959.getter_string (SOURCE_FILE ("gtl_parser.galgas", 411))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 410))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 409)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_parser.galgas", 415)) ;
    nt_gtl_5F_expression_ (outArgument_expression, inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_parser_25 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 408)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_parser.galgas", 415)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  GALGAS_location var_where_1050 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  GALGAS_gtlVarPath var_variable_1097 ;
  nt_gtl_5F_variable_ (var_variable_1097, inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 46)) ;
    GALGAS_gtlExpression var_expression_1163 ;
    nt_gtl_5F_expression_ (var_expression_1163, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_1163  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 48)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 50)) ;
    GALGAS_gtlExpression var_expression_1299 ;
    nt_gtl_5F_expression_ (var_expression_1299, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAddInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_1299  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 52)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 54)) ;
    GALGAS_gtlExpression var_expression_1438 ;
    nt_gtl_5F_expression_ (var_expression_1438, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetSubstractInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_1438  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 56)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 58)) ;
    GALGAS_gtlExpression var_expression_1583 ;
    nt_gtl_5F_expression_ (var_expression_1583, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetMultiplyInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_1583  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 60)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 62)) ;
    GALGAS_gtlExpression var_expression_1727 ;
    nt_gtl_5F_expression_ (var_expression_1727, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetDivideInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_1727  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 64)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 66)) ;
    GALGAS_gtlExpression var_expression_1871 ;
    nt_gtl_5F_expression_ (var_expression_1871, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetModuloInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_1871  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 68)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 70)) ;
    GALGAS_gtlExpression var_expression_2014 ;
    nt_gtl_5F_expression_ (var_expression_2014, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftLeftInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_2014  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 72)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 74)) ;
    GALGAS_gtlExpression var_expression_2160 ;
    nt_gtl_5F_expression_ (var_expression_2160, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftRightInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_2160  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 76)) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 78)) ;
    GALGAS_gtlExpression var_expression_2306 ;
    nt_gtl_5F_expression_ (var_expression_2306, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAndInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_2306  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 80)) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 82)) ;
    GALGAS_gtlExpression var_expression_2445 ;
    nt_gtl_5F_expression_ (var_expression_2445, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetOrInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_2445  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 84)) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 86)) ;
    GALGAS_gtlExpression var_expression_2583 ;
    nt_gtl_5F_expression_ (var_expression_2583, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetXorInstruction::constructor_new (var_where_1050, var_variable_1097, var_expression_2583  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 88)) ;
  } break ;
  case 12: {
    outArgument_instruction = GALGAS_gtlLetUnconstructedInstruction::constructor_new (var_where_1050, var_variable_1097  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 90)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 46)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 50)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 54)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 58)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 62)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 66)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 70)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 74)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 78)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 82)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 86)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 12: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 98)) ;
  GALGAS_location var_where_2917 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 98)) ;
  GALGAS_gtlVarPath var_variable_2964 ;
  nt_gtl_5F_variable_ (var_variable_2964, inCompiler) ;
  outArgument_instruction = GALGAS_gtlUnletInstruction::constructor_new (var_where_2917, var_variable_2964  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 100)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 98)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_error) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 107)) ;
  GALGAS_location var_where_3198 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 107)) ;
  GALGAS_gtlVarPath var_variable_3253 ;
  GALGAS_bool var_hereInstead_3272 ;
  nt_gtl_5F_variable_5F_or_5F_here_ (var_variable_3253, var_hereInstead_3272, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 109)) ;
  GALGAS_gtlExpression var_expression_3324 ;
  nt_gtl_5F_expression_ (var_expression_3324, inCompiler) ;
  outArgument_instruction = GALGAS_gtlErrorStatementInstruction::constructor_new (var_where_3198, var_variable_3253, var_hereInstead_3272, var_expression_3324  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 112)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_error) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 107)) ;
  nt_gtl_5F_variable_5F_or_5F_here_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 109)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_warning) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 121)) ;
  GALGAS_location var_where_3601 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 121)) ;
  GALGAS_gtlVarPath var_variable_3656 ;
  GALGAS_bool var_hereInstead_3675 ;
  nt_gtl_5F_variable_5F_or_5F_here_ (var_variable_3656, var_hereInstead_3675, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 123)) ;
  GALGAS_gtlExpression var_expression_3727 ;
  nt_gtl_5F_expression_ (var_expression_3727, inCompiler) ;
  outArgument_instruction = GALGAS_gtlWarningStatementInstruction::constructor_new (var_where_3601, var_variable_3656, var_hereInstead_3675, var_expression_3727  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 126)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_warning) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 121)) ;
  nt_gtl_5F_variable_5F_or_5F_here_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 123)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 135)) ;
  GALGAS_location var_where_4004 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 135)) ;
  GALGAS_gtlExpression var_expression_4058 ;
  nt_gtl_5F_expression_ (var_expression_4058, inCompiler) ;
  outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_4004, GALGAS_bool (false), var_expression_4058  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 138)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 135)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_println) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 147)) ;
  GALGAS_location var_where_4319 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 147)) ;
  switch (select_gtl_5F_instruction_5F_parser_1 (inCompiler)) {
  case 1: {
    GALGAS_gtlExpression var_expression_4384 ;
    nt_gtl_5F_expression_ (var_expression_4384, inCompiler) ;
    outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_4319, GALGAS_bool (true), var_expression_4384  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 150)) ;
  } break ;
  case 2: {
    outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_4319, GALGAS_bool (true), GALGAS_gtlTerminal::constructor_new (var_where_4319, GALGAS_gtlString::constructor_new (var_where_4319, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 154)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_println) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 147)) ;
  switch (select_gtl_5F_instruction_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 166)) ;
  GALGAS_location var_where_4832 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 166)) ;
  GALGAS_gtlVarPath var_variable_4879 ;
  nt_gtl_5F_variable_ (var_variable_4879, inCompiler) ;
  outArgument_instruction = GALGAS_gtlDisplayStatementInstruction::constructor_new (var_where_4832, var_variable_4879  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 169)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 166)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_sort) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 178)) ;
  GALGAS_location var_where_5130 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 178)) ;
  GALGAS_gtlVarPath var_variable_5177 ;
  nt_gtl_5F_variable_ (var_variable_5177, inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_2 (inCompiler)) {
  case 1: {
    GALGAS_sortingKeyList var_sortList_5215 = GALGAS_sortingKeyList::constructor_emptyList (SOURCE_FILE ("gtl_instruction_parser.galgas", 181)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 182)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_key_5285 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 184)) ;
      GALGAS_lsint var_order_5325 ;
      nt_gtl_5F_sorting_5F_order_ (var_order_5325, inCompiler) ;
      var_sortList_5215.addAssign_operation (var_key_5285, var_order_5325  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 186)) ;
      switch (select_gtl_5F_instruction_5F_parser_3 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 187)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    outArgument_instruction = GALGAS_gtlSortStatementStructInstruction::constructor_new (var_where_5130, var_variable_5177, var_sortList_5215  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 189)) ;
  } break ;
  case 2: {
    GALGAS_lsint var_order_5523 ;
    nt_gtl_5F_sorting_5F_order_ (var_order_5523, inCompiler) ;
    outArgument_instruction = GALGAS_gtlSortStatementInstruction::constructor_new (var_where_5130, var_variable_5177, var_order_5523  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 195)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_sort) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 178)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 182)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 184)) ;
      nt_gtl_5F_sorting_5F_order_parse (inCompiler) ;
      switch (select_gtl_5F_instruction_5F_parser_3 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 187)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
    nt_gtl_5F_sorting_5F_order_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_tab) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 205)) ;
  GALGAS_location var_where_5793 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 205)) ;
  GALGAS_gtlExpression var_expression_5847 ;
  nt_gtl_5F_expression_ (var_expression_5847, inCompiler) ;
  outArgument_instruction = GALGAS_gtlTabStatementInstruction::constructor_new (var_where_5793, var_expression_5847  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 208)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_tab) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 205)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 217)) ;
  GALGAS_location var_where_6105 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 217)) ;
  outArgument_instruction = GALGAS_gtlVariablesInstruction::constructor_new (var_where_6105  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 218)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 217)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                                C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_libraries) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 225)) ;
  GALGAS_location var_where_6345 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 225)) ;
  outArgument_instruction = GALGAS_gtlLibrariesInstruction::constructor_new (var_where_6345  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 226)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_libraries) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 225)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                                C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B__21_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 233)) ;
  GALGAS_gtlVarPath var_target_6599 ;
  nt_gtl_5F_variable_ (var_target_6599, inCompiler) ;
  GALGAS_lstring var_setterName_6639 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 235)) ;
  GALGAS_gtlExpressionList var_argumentList_6673 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_instruction_parser.galgas", 236)) ;
  switch (select_gtl_5F_instruction_5F_parser_4 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 239)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_argument_6767 ;
      nt_gtl_5F_expression_ (var_argument_6767, inCompiler) ;
      var_argumentList_6673.addAssign_operation (var_argument_6767  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 242)) ;
      switch (select_gtl_5F_instruction_5F_parser_5 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 244)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 247)) ;
  outArgument_instruction = GALGAS_gtlSetterCallInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 249)), var_target_6599, var_setterName_6639, var_argumentList_6673  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 248)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B__21_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 233)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 235)) ;
  switch (select_gtl_5F_instruction_5F_parser_4 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 239)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_instruction_5F_parser_5 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 244)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 247)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_ (GALGAS_lsint & outArgument_order,
                                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_order.drop () ; // Release 'out' argument
  switch (select_gtl_5F_instruction_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 261)) ;
    outArgument_order = GALGAS_lsint::constructor_new (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 262)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 262))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 262)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 264)) ;
    outArgument_order = GALGAS_lsint::constructor_new (GALGAS_sint ((int32_t) 1L), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 265))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 265)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_instruction_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 261)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 264)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_ (GALGAS_gtlContext inArgument_context,
                                                                                                 GALGAS_library & ioArgument_lib,
                                                                                                 C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_import) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 274)) ;
  GALGAS_lstring var_fileName_7395 = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 274)) ;
  GALGAS_string var_fullName_7414 = var_fileName_7395.getter_string (SOURCE_FILE ("gtl_instruction_parser.galgas", 275)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_fullName_7414.getter_pathExtension (SOURCE_FILE ("gtl_instruction_parser.galgas", 276)).objectCompare (GALGAS_string ("gtm"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_fullName_7414 = var_fileName_7395.getter_string (SOURCE_FILE ("gtl_instruction_parser.galgas", 277)).add_operation (GALGAS_string (".gtm"), inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 277)) ;
  }
  GALGAS_bool var_found_7543 = GALGAS_bool (false) ;
  const enumGalgasBool test_1 = var_fullName_7414.getter_fileExists (SOURCE_FILE ("gtl_instruction_parser.galgas", 281)).operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 281)).boolEnum () ;
  if (kBoolTrue == test_1) {
    cEnumerator_stringlist enumerator_7653 (inArgument_context.getter_importPath (SOURCE_FILE ("gtl_instruction_parser.galgas", 283)), kEnumeration_up) ;
    while (enumerator_7653.hasCurrentObject ()) {
      const enumGalgasBool test_2 = var_found_7543.operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 284)).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_string var_name_7701 = extensionGetter_stringByAppendingPath (enumerator_7653.current_mValue (HERE), var_fullName_7414, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 285)) ;
        const enumGalgasBool test_3 = var_name_7701.getter_fileExists (SOURCE_FILE ("gtl_instruction_parser.galgas", 286)).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_fullName_7414 = var_name_7701 ;
          var_found_7543 = GALGAS_bool (true) ;
        }
      }
      enumerator_7653.gotoNextObject () ;
    }
  }else if (kBoolFalse == test_1) {
    var_found_7543 = GALGAS_bool (true) ;
  }
  const enumGalgasBool test_4 = var_found_7543.boolEnum () ;
  if (kBoolTrue == test_4) {
    const enumGalgasBool test_5 = callExtensionGetter_hasImport ((const cPtr_library *) ioArgument_lib.ptr (), var_fullName_7414, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 297)).operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 297)).boolEnum () ;
    if (kBoolTrue == test_5) {
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_7965 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_doImport ((cPtr_library *) ptr_7965, var_fullName_7414, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 298)) ;
      }
      cGrammar_gtl_5F_module_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_fullName_7414, var_fileName_7395.getter_location (SOURCE_FILE ("gtl_instruction_parser.galgas", 300))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 300)), inArgument_context, ioArgument_lib  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 299)) ;
    }
  }else if (kBoolFalse == test_4) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 303)), GALGAS_string ("module not found"), fixItArray6  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 303)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_import) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 274)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 274)) ;
  inCompiler->resetTemplateString () ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_ (GALGAS_gtlInstructionList & outArgument_instructionList,
                                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instructionList.drop () ; // Release 'out' argument
  outArgument_instructionList = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 48)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_0 (inCompiler)) {
    case 2: {
      GALGAS_gtlInstruction var_instruction_1351 ;
      nt_gtl_5F_instruction_ (var_instruction_1351, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1351  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 53)) ;
      GALGAS_string var_templateString_1414 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 54)) ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_templateString_1414.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_instructionList.addAssign_operation (GALGAS_gtlTemplateStringInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 57)), var_templateString_1414  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 57))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 56)) ;
      }
    } break ;
    case 3: {
      GALGAS_gtlInstruction var_instruction_1656 ;
      nt_gtl_5F_simple_5F_instruction_ (var_instruction_1656, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1656  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 61)) ;
      GALGAS_string var_templateString_1719 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 62)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_templateString_1719.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_instructionList.addAssign_operation (GALGAS_gtlTemplateStringInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 65)), var_templateString_1719  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 65))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 64)) ;
      }
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_instruction_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_simple_5F_instruction_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_ (GALGAS_gtlContext inArgument_context,
                                                                                                         GALGAS_library & ioArgument_lib,
                                                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_ (inArgument_context, ioArgument_lib, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_gtl_5F_module_5F_parser_2 (inCompiler)) {
    case 2: {
      GALGAS_gtlFunction var_aFunction_2280 ;
      nt_gtl_5F_function_ (var_aFunction_2280, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2291 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putFunction ((cPtr_library *) ptr_2291, var_aFunction_2280.getter_name (SOURCE_FILE ("gtl_module_parser.galgas", 85)), var_aFunction_2280, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 85)) ;
      }
    } break ;
    case 3: {
      GALGAS_gtlGetter var_aGetter_2378 ;
      nt_gtl_5F_getter_ (var_aGetter_2378, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2389 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putGetter ((cPtr_library *) ptr_2389, callExtensionGetter_typedName ((const cPtr_gtlGetter *) var_aGetter_2378.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 88)), var_aGetter_2378, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 88)) ;
      }
    } break ;
    case 4: {
      GALGAS_gtlSetter var_aSetter_2475 ;
      nt_gtl_5F_setter_ (var_aSetter_2475, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2486 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putSetter ((cPtr_library *) ptr_2486, callExtensionGetter_typedName ((const cPtr_gtlSetter *) var_aSetter_2475.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 91)), var_aSetter_2475, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 91)) ;
      }
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_gtl_5F_module_5F_parser_2 (inCompiler)) {
    case 2: {
      nt_gtl_5F_function_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_getter_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_gtl_5F_setter_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_ (GALGAS_gtlFunction & outArgument_function,
                                                                                        C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_function.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_func) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 101)) ;
  GALGAS_lstring var_functionName_2816 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 102)) ;
  GALGAS_location var_where_2834 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 103)) ;
  GALGAS_gtlArgumentList var_arguments_2892 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_2892, inCompiler) ;
  GALGAS_lstring var_returnVariable_2936 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 105)) ;
  GALGAS_gtlInstructionList var_instructionList_3002 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_3002, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 107)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_func) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 107)) ;
  outArgument_function = GALGAS_gtlFunction::constructor_new (var_where_2834, var_functionName_2816, var_arguments_2892, var_instructionList_3002, var_returnVariable_2936  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 109)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_func) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 101)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 102)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 105)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 107)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_func) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 107)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_ (GALGAS_gtlGetter & outArgument_aGetter,
                                                                                      C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_aGetter.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_getter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 120)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 121)) ;
  GALGAS_lstring var_targetType_3393 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 121)) ;
  GALGAS_lstring var_getterName_3433 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 122)) ;
  GALGAS_location var_where_3451 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 123)) ;
  GALGAS_gtlArgumentList var_arguments_3509 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_3509, inCompiler) ;
  GALGAS_lstring var_returnVariable_3553 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 125)) ;
  GALGAS_gtlInstructionList var_instructionList_3619 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_3619, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 127)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_getter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 127)) ;
  outArgument_aGetter = GALGAS_gtlGetter::constructor_new (var_where_3451, var_getterName_3433, var_arguments_3509, var_instructionList_3619, var_returnVariable_3553, extensionGetter_gtlType (var_targetType_3393, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 135))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 129)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_getter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 120)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 121)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 121)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 122)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 125)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 127)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_getter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 127)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_ (GALGAS_gtlSetter & outArgument_aSetter,
                                                                                      C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_aSetter.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_setter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 145)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 146)) ;
  GALGAS_lstring var_targetType_4051 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 146)) ;
  GALGAS_lstring var_getterName_4091 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 147)) ;
  GALGAS_location var_where_4109 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 148)) ;
  GALGAS_gtlArgumentList var_arguments_4167 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_4167, inCompiler) ;
  GALGAS_gtlInstructionList var_instructionList_4233 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_4233, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 151)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_setter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 151)) ;
  outArgument_aSetter = GALGAS_gtlSetter::constructor_new (var_where_4109, var_getterName_4091, var_arguments_4167, var_instructionList_4233, extensionGetter_gtlType (var_targetType_4051, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 158))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 153)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_setter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 145)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 146)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 146)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 147)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 151)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_setter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 151)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlThenElsifStatementList var_thenElsifList_4686 = GALGAS_gtlThenElsifStatementList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 168)) ;
  GALGAS_gtlInstructionList var_elseList_4730 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 169)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 171)) ;
  GALGAS_location var_where_4769 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 171)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlExpression var_condition_4833 ;
    nt_gtl_5F_expression_ (var_condition_4833, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 174)) ;
    GALGAS_gtlInstructionList var_instructionList_4908 ;
    nt_gtl_5F_instruction_5F_list_ (var_instructionList_4908, inCompiler) ;
    var_thenElsifList_4686.addAssign_operation (var_condition_4833, var_instructionList_4908  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 177)) ;
    switch (select_gtl_5F_module_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 179)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_module_5F_parser_4 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 183)) ;
    nt_gtl_5F_instruction_5F_list_ (var_elseList_4730, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 187)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 188)) ;
  outArgument_instruction = GALGAS_gtlIfStatementInstruction::constructor_new (var_where_4769, var_thenElsifList_4686, var_elseList_4730  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 190)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 171)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 174)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
    switch (select_gtl_5F_module_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 179)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_module_5F_parser_4 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 183)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 187)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 188)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_5462 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 201)) ;
  GALGAS_gtlInstructionList var_doList_5504 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 202)) ;
  GALGAS_gtlInstructionList var_betweenList_5551 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
  GALGAS_gtlInstructionList var_afterList_5596 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 204)) ;
  GALGAS_lstring var_indexName_5630 ;
  GALGAS_lstring var_variableName_5654 ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 208)) ;
  GALGAS_location var_where_5683 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 208)) ;
  GALGAS_lstring var_keyName_5728 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
  switch (select_gtl_5F_module_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 211)) ;
    var_variableName_5654 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 211)) ;
  } break ;
  case 2: {
    var_variableName_5654 = var_keyName_5728 ;
    var_keyName_5728 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), var_where_5683  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 214)) ;
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
    var_indexName_5630 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
  } break ;
  case 2: {
    var_indexName_5630 = GALGAS_lstring::constructor_new (GALGAS_string ("INDEX"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 219))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 219)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 221)) ;
  GALGAS_gtlExpression var_iterable_5992 ;
  nt_gtl_5F_expression_ (var_iterable_5992, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 225)) ;
    nt_gtl_5F_instruction_5F_list_ (var_beforeList_5462, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 229)) ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_5504, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 233)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_5551, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 238)) ;
    nt_gtl_5F_instruction_5F_list_ (var_afterList_5596, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 242)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 243)) ;
  outArgument_instruction = GALGAS_gtlForeachStatementInstruction::constructor_new (var_where_5683, var_keyName_5728, var_variableName_5654, var_indexName_5630, var_iterable_5992, var_beforeList_5462, var_betweenList_5551, var_afterList_5596, var_doList_5504  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 245)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 208)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
  switch (select_gtl_5F_module_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 211)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 211)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 221)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 225)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 229)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 233)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 238)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 242)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 243)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_doList_6809 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 264)) ;
  GALGAS_gtlInstructionList var_betweenList_6856 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 265)) ;
  GALGAS_gtlExpressionList var_iterable_6900 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 266)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 268)) ;
  GALGAS_location var_where_6939 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 268)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("foreach var in @( expression, ..., expression )")) ;
    inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 270)), GALGAS_string ("for var in expression, ..., expression is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 270)) ;
  }
  GALGAS_lstring var_variableName_7196 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 273)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 274)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    GALGAS_gtlExpression var_expression_7260 ;
    nt_gtl_5F_expression_ (var_expression_7260, inCompiler) ;
    var_iterable_6900.addAssign_operation (var_expression_7260  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 277)) ;
    switch (select_gtl_5F_module_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 279)) ;
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 282)) ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_6809, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 286)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_6856, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 290)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 291)) ;
  outArgument_instruction = GALGAS_gtlForStatementInstruction::constructor_new (var_where_6939, var_variableName_7196, var_iterable_6900, var_betweenList_6856, var_doList_6809  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 293)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 268)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 273)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 274)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    switch (select_gtl_5F_module_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 279)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 282)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 286)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 290)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 291)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_7872 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 304)) ;
  GALGAS_gtlInstructionList var_betweenList_7919 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 305)) ;
  GALGAS_gtlInstructionList var_afterList_7964 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 306)) ;
  GALGAS_sint_36__34_ var_direction_7997 = GALGAS_sint_36__34_ ((int64_t) 1LL) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 309)) ;
  GALGAS_location var_where_8031 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 309)) ;
  GALGAS_gtlExpression var_step_8062 = GALGAS_gtlTerminal::constructor_new (var_where_8031, GALGAS_gtlInt::constructor_new (var_where_8031, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 312)), GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 312))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 312))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 311)) ;
  GALGAS_lstring var_variableName_8187 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 315)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 316)) ;
  GALGAS_gtlExpression var_start_8237 ;
  nt_gtl_5F_expression_ (var_start_8237, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_12 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 320)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 322)) ;
    var_direction_7997 = GALGAS_sint_36__34_ ((int64_t) 1LL).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 322)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 324)) ;
  GALGAS_gtlExpression var_stop_8347 ;
  nt_gtl_5F_expression_ (var_stop_8347, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 327)) ;
    nt_gtl_5F_expression_ (var_step_8062, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 332)) ;
    nt_gtl_5F_instruction_5F_list_ (var_beforeList_7872, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 336)) ;
  GALGAS_gtlInstructionList var_doList_8565 ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_8565, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 340)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_7919, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 345)) ;
    nt_gtl_5F_instruction_5F_list_ (var_afterList_7964, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 349)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 350)) ;
  outArgument_instruction = GALGAS_gtlLoopStatementInstruction::constructor_new (var_where_8031, var_variableName_8187, var_start_8237, var_stop_8347, var_step_8062, var_direction_7997, var_beforeList_7872, var_betweenList_7919, var_afterList_7964, var_doList_8565  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 352)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 309)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 315)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 316)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_12 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 320)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 322)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 324)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 327)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 332)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 336)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 340)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 345)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 349)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 350)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlExpression var_limit_9198 ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 366)) ;
  GALGAS_location var_where_9228 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 366)) ;
  switch (select_gtl_5F_module_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 368)) ;
    nt_gtl_5F_expression_ (var_limit_9198, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 370)) ;
  } break ;
  case 2: {
    var_limit_9198 = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 373)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 374)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 374)), GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_module_parser.galgas", 374)).getter_bigint (SOURCE_FILE ("gtl_module_parser.galgas", 374))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 374))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 372)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_gtlInstructionList var_continueList_9476 ;
  nt_gtl_5F_instruction_5F_list_ (var_continueList_9476, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 378)) ;
  GALGAS_gtlExpression var_condition_9531 ;
  nt_gtl_5F_expression_ (var_condition_9531, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 380)) ;
  GALGAS_gtlInstructionList var_doList_9591 ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_9591, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 382)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 383)) ;
  outArgument_instruction = GALGAS_gtlRepeatStatementInstruction::constructor_new (var_where_9228, var_limit_9198, var_condition_9531, var_continueList_9476, var_doList_9591  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 385)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 366)) ;
  switch (select_gtl_5F_module_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 368)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 370)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 378)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 380)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 382)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 383)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_gtl_grammar [] = {
// At index 0 : <gtl_expression>, in file 'gtl_expression_parser.ggs', line 33
  NONTERMINAL (10) // <gtl_relation_term>
, NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 3 : <gtl_variable>, in file 'gtl_expression_parser.ggs', line 667
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (63) // <select_gtl_5F_expression_5F_parser_21>
, NONTERMINAL (62) // <select_gtl_5F_expression_5F_parser_20>
, END_PRODUCTION
// At index 7 : <gtl_variable_or_here>, in file 'gtl_expression_parser.ggs', line 702
, NONTERMINAL (66) // <select_gtl_5F_expression_5F_parser_24>
, END_PRODUCTION
// At index 9 : <gtl_import>, in file 'gtl_instruction_parser.ggs', line 270
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_import) // $import$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, END_PRODUCTION
// At index 12 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 40
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) // $let$
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (70) // <select_gtl_5F_instruction_5F_parser_0>
, END_PRODUCTION
// At index 16 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 95
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) // $unlet$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 19 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 104
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_error) // $error$
, NONTERMINAL (2) // <gtl_variable_or_here>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 24 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 118
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_warning) // $warning$
, NONTERMINAL (2) // <gtl_variable_or_here>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 29 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 132
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) // $print$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 32 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 144
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_println) // $println$
, NONTERMINAL (71) // <select_gtl_5F_instruction_5F_parser_1>
, END_PRODUCTION
// At index 35 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 163
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) // $display$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 38 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 175
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_sort) // $sort$
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (72) // <select_gtl_5F_instruction_5F_parser_2>
, END_PRODUCTION
// At index 42 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 202
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_tab) // $tab$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 45 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 214
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) // $variables$
, END_PRODUCTION
// At index 47 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 222
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_libraries) // $libraries$
, END_PRODUCTION
// At index 49 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 230
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B__21_) // $[!$
, NONTERMINAL (1) // <gtl_variable>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (74) // <select_gtl_5F_instruction_5F_parser_4>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 55 : <gtl_argument_list>, in file 'gtl_expression_parser.ggs', line 716
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (67) // <select_gtl_5F_expression_5F_parser_25>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 59 : <gtl_start_symbol>, in file 'gtl_parser.ggs', line 50
, NONTERMINAL (16) // <select_gtl_5F_parser_0>
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 62 : <gtl_template_instruction_list>, in file 'gtl_parser.ggs', line 63
, NONTERMINAL (17) // <select_gtl_5F_parser_1>
, END_PRODUCTION
// At index 64 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 86
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) // $!$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 67 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 100
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) // $write$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) // $to$
, NONTERMINAL (18) // <select_gtl_5F_parser_2>
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) // $write$
, END_PRODUCTION
// At index 76 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 116
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) // $template$
, NONTERMINAL (19) // <select_gtl_5F_parser_3>
, NONTERMINAL (22) // <select_gtl_5F_parser_6>
, END_PRODUCTION
// At index 80 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 170
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3F_) // $?$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 83 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 181
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) // $if$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) // $then$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (26) // <select_gtl_5F_parser_10>
, NONTERMINAL (27) // <select_gtl_5F_parser_11>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) // $if$
, END_PRODUCTION
// At index 92 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 211
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) // $foreach$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (28) // <select_gtl_5F_parser_12>
, NONTERMINAL (29) // <select_gtl_5F_parser_13>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) // $in$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (30) // <select_gtl_5F_parser_14>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (31) // <select_gtl_5F_parser_15>
, NONTERMINAL (32) // <select_gtl_5F_parser_16>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) // $foreach$
, END_PRODUCTION
// At index 106 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 271
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) // $for$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) // $in$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (33) // <select_gtl_5F_parser_17>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (34) // <select_gtl_5F_parser_18>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) // $for$
, END_PRODUCTION
// At index 117 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 308
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) // $loop$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) // $from$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (35) // <select_gtl_5F_parser_19>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) // $to$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (36) // <select_gtl_5F_parser_20>
, NONTERMINAL (37) // <select_gtl_5F_parser_21>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (38) // <select_gtl_5F_parser_22>
, NONTERMINAL (39) // <select_gtl_5F_parser_23>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) // $loop$
, END_PRODUCTION
// At index 133 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 365
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) // $repeat$
, NONTERMINAL (40) // <select_gtl_5F_parser_24>
, NONTERMINAL (7) // <gtl_template_instruction_list>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) // $while$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) // $repeat$
, END_PRODUCTION
// At index 143 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 393
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_input) // $input$
, NONTERMINAL (5) // <gtl_argument_list>
, END_PRODUCTION
// At index 146 : <gtl_file_name>, in file 'gtl_parser.ggs', line 404
, NONTERMINAL (41) // <select_gtl_5F_parser_25>
, END_PRODUCTION
// At index 148 : <gtl_relation_term>, in file 'gtl_expression_parser.ggs', line 53
, NONTERMINAL (11) // <gtl_relation_factor>
, NONTERMINAL (43) // <select_gtl_5F_expression_5F_parser_1>
, END_PRODUCTION
// At index 151 : <gtl_relation_factor>, in file 'gtl_expression_parser.ggs', line 69
, NONTERMINAL (12) // <gtl_simple_expression>
, NONTERMINAL (44) // <select_gtl_5F_expression_5F_parser_2>
, END_PRODUCTION
// At index 154 : <gtl_simple_expression>, in file 'gtl_expression_parser.ggs', line 117
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 157 : <gtl_term>, in file 'gtl_expression_parser.ggs', line 162
, NONTERMINAL (14) // <gtl_factor>
, NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 160 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 192
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 164 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 208
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) // $not$
, NONTERMINAL (14) // <gtl_factor>
, END_PRODUCTION
// At index 167 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 220
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7E_) // $~$
, NONTERMINAL (14) // <gtl_factor>
, END_PRODUCTION
// At index 170 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 232
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (14) // <gtl_factor>
, END_PRODUCTION
// At index 173 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 244
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) // $+$
, NONTERMINAL (14) // <gtl_factor>
, END_PRODUCTION
// At index 176 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 256
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_yes) // $yes$
, END_PRODUCTION
// At index 178 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 269
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_no) // $no$
, END_PRODUCTION
// At index 180 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 282
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, END_PRODUCTION
// At index 182 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 295
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double) // $literal_double$
, END_PRODUCTION
// At index 184 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 308
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, END_PRODUCTION
// At index 186 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 321
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char) // $literal_char$
, END_PRODUCTION
// At index 188 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 335
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (47) // <select_gtl_5F_expression_5F_parser_5>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 194 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 369
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (49) // <select_gtl_5F_expression_5F_parser_7>
, END_PRODUCTION
// At index 197 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 401
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) // $exists$
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (52) // <select_gtl_5F_expression_5F_parser_10>
, END_PRODUCTION
// At index 201 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 420
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_typeof) // $typeof$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 204 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 429
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_true) // $true$
, END_PRODUCTION
// At index 206 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 445
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_false) // $false$
, END_PRODUCTION
// At index 208 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 461
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum) // $literal_enum$
, END_PRODUCTION
// At index 210 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 477
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) // $@$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 213 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 514
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptylist) // $emptylist$
, END_PRODUCTION
// At index 215 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 533
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptymap) // $emptymap$
, END_PRODUCTION
// At index 217 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 552
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mapof) // $mapof$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (53) // <select_gtl_5F_expression_5F_parser_11>
, END_PRODUCTION
// At index 221 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 576
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_listof) // $listof$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, END_PRODUCTION
// At index 225 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 587
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__28_) // $@($
, NONTERMINAL (54) // <select_gtl_5F_expression_5F_parser_12>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 229 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 606
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__5B_) // $@[$
, NONTERMINAL (56) // <select_gtl_5F_expression_5F_parser_14>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 233 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 627
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__7B_) // $@{$
, NONTERMINAL (58) // <select_gtl_5F_expression_5F_parser_16>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7D_) // $}$
, END_PRODUCTION
// At index 237 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 648
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__21_) // $@!$
, NONTERMINAL (60) // <select_gtl_5F_expression_5F_parser_18>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) // $!$
, END_PRODUCTION
// At index 241 : <gtl_sorting_order>, in file 'gtl_instruction_parser.ggs', line 257
, NONTERMINAL (76) // <select_gtl_5F_instruction_5F_parser_6>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 243 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
, END_PRODUCTION
// At index 244 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
, NONTERMINAL (3) // <gtl_import>
, NONTERMINAL (16) // <select_gtl_5F_parser_0>
, END_PRODUCTION
// At index 247 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, END_PRODUCTION
// At index 248 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, NONTERMINAL (8) // <gtl_template_instruction>
, NONTERMINAL (17) // <select_gtl_5F_parser_1>
, END_PRODUCTION
// At index 251 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, NONTERMINAL (4) // <gtl_simple_instruction>
, NONTERMINAL (17) // <select_gtl_5F_parser_1>
, END_PRODUCTION
// At index 254 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 104
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_executable) // $executable$
, END_PRODUCTION
// At index 256 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 104
, END_PRODUCTION
// At index 257 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 126
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (20) // <select_gtl_5F_parser_4>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 261 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 126
, END_PRODUCTION
// At index 262 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 129
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (21) // <select_gtl_5F_parser_5>
, END_PRODUCTION
// At index 265 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 129
, END_PRODUCTION
// At index 266 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 130
, END_PRODUCTION
// At index 267 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 130
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (21) // <select_gtl_5F_parser_5>
, END_PRODUCTION
// At index 271 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 140
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) // $if$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) // $exists$
, NONTERMINAL (9) // <gtl_file_name>
, NONTERMINAL (23) // <select_gtl_5F_parser_7>
, NONTERMINAL (24) // <select_gtl_5F_parser_8>
, END_PRODUCTION
// At index 277 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 140
, NONTERMINAL (9) // <gtl_file_name>
, NONTERMINAL (25) // <select_gtl_5F_parser_9>
, END_PRODUCTION
// At index 280 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 144
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) // $in$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 283 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 144
, END_PRODUCTION
// At index 284 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 147
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_or) // $or$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) // $template$
, END_PRODUCTION
// At index 289 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 147
, END_PRODUCTION
// At index 290 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 154
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) // $in$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 293 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 154
, END_PRODUCTION
// At index 294 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 187
, END_PRODUCTION
// At index 295 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 187
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) // $elsif$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) // $then$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (26) // <select_gtl_5F_parser_10>
, END_PRODUCTION
// At index 301 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 197
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) // $else$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 304 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 197
, END_PRODUCTION
// At index 305 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 222
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 308 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 222
, END_PRODUCTION
// At index 309 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 228
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 313 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 228
, END_PRODUCTION
// At index 314 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 236
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) // $before$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 317 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 236
, END_PRODUCTION
// At index 318 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 244
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) // $between$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 321 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 244
, END_PRODUCTION
// At index 322 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 249
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) // $after$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 325 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 249
, END_PRODUCTION
// At index 326 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 284
, END_PRODUCTION
// At index 327 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 284
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (33) // <select_gtl_5F_parser_17>
, END_PRODUCTION
// At index 331 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 294
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) // $between$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 334 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 294
, END_PRODUCTION
// At index 335 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 324
, END_PRODUCTION
// At index 336 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 324
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) // $up$
, END_PRODUCTION
// At index 338 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 324
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) // $down$
, END_PRODUCTION
// At index 340 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 332
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) // $step$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 343 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 332
, END_PRODUCTION
// At index 344 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 337
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) // $before$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 347 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 337
, END_PRODUCTION
// At index 348 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 345
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) // $between$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 351 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 345
, END_PRODUCTION
// At index 352 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 350
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) // $after$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 355 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 350
, END_PRODUCTION
// At index 356 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 370
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 360 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 370
, END_PRODUCTION
// At index 361 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 407
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 363 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 407
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) // $from$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 366 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, END_PRODUCTION
// At index 367 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C_) // $|$
, NONTERMINAL (10) // <gtl_relation_term>
, NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 371 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E_) // $^$
, NONTERMINAL (10) // <gtl_relation_term>
, NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 375 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
, END_PRODUCTION
// At index 376 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26_) // $&$
, NONTERMINAL (11) // <gtl_relation_factor>
, NONTERMINAL (43) // <select_gtl_5F_expression_5F_parser_1>
, END_PRODUCTION
// At index 380 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, END_PRODUCTION
// At index 381 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3D__3D_) // $==$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 384 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21__3D_) // $!=$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 387 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3D_) // $<=$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 390 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3D_) // $>=$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 393 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 396 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) // $<$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 399 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, END_PRODUCTION
// At index 400 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C_) // $<<$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 404 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E_) // $>>$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 408 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) // $+$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 412 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) // $.$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 416 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 420 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, END_PRODUCTION
// At index 421 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A_) // $*$
, NONTERMINAL (14) // <gtl_factor>
, NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 425 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F_) // $/$
, NONTERMINAL (14) // <gtl_factor>
, NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 429 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod) // $mod$
, NONTERMINAL (14) // <gtl_factor>
, NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 433 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
, END_PRODUCTION
// At index 434 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (48) // <select_gtl_5F_expression_5F_parser_6>
, END_PRODUCTION
// At index 438 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
, END_PRODUCTION
// At index 439 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (48) // <select_gtl_5F_expression_5F_parser_6>
, END_PRODUCTION
// At index 443 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
, END_PRODUCTION
// At index 444 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (50) // <select_gtl_5F_expression_5F_parser_8>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 448 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (51) // <select_gtl_5F_expression_5F_parser_9>
, END_PRODUCTION
// At index 451 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
, END_PRODUCTION
// At index 452 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
, END_PRODUCTION
// At index 453 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (51) // <select_gtl_5F_expression_5F_parser_9>
, END_PRODUCTION
// At index 457 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_default) // $default$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 462 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
, END_PRODUCTION
// At index 463 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) // $by$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 466 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, END_PRODUCTION
// At index 468 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (55) // <select_gtl_5F_expression_5F_parser_13>
, END_PRODUCTION
// At index 471 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
, END_PRODUCTION
// At index 472 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
, END_PRODUCTION
// At index 473 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (55) // <select_gtl_5F_expression_5F_parser_13>
, END_PRODUCTION
// At index 477 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (57) // <select_gtl_5F_expression_5F_parser_15>
, END_PRODUCTION
// At index 482 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
, END_PRODUCTION
// At index 483 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
, END_PRODUCTION
// At index 484 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (57) // <select_gtl_5F_expression_5F_parser_15>
, END_PRODUCTION
// At index 490 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (59) // <select_gtl_5F_expression_5F_parser_17>
, END_PRODUCTION
// At index 495 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
, END_PRODUCTION
// At index 496 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
, END_PRODUCTION
// At index 497 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (59) // <select_gtl_5F_expression_5F_parser_17>
, END_PRODUCTION
// At index 503 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (61) // <select_gtl_5F_expression_5F_parser_19>
, END_PRODUCTION
// At index 506 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
, END_PRODUCTION
// At index 507 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
, END_PRODUCTION
// At index 508 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (61) // <select_gtl_5F_expression_5F_parser_19>
, END_PRODUCTION
// At index 512 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
, END_PRODUCTION
// At index 513 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3A_) // $::$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (63) // <select_gtl_5F_expression_5F_parser_21>
, NONTERMINAL (62) // <select_gtl_5F_expression_5F_parser_20>
, END_PRODUCTION
// At index 518 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (64) // <select_gtl_5F_expression_5F_parser_22>
, END_PRODUCTION
// At index 523 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
, END_PRODUCTION
// At index 524 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (65) // <select_gtl_5F_expression_5F_parser_23>
, END_PRODUCTION
// At index 529 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
, END_PRODUCTION
// At index 530 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
, END_PRODUCTION
// At index 531 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (65) // <select_gtl_5F_expression_5F_parser_23>
, END_PRODUCTION
// At index 536 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) // $here$
, END_PRODUCTION
// At index 538 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 540 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (69) // <select_gtl_5F_expression_5F_parser_27>
, NONTERMINAL (68) // <select_gtl_5F_expression_5F_parser_26>
, END_PRODUCTION
// At index 544 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
, END_PRODUCTION
// At index 545 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
, END_PRODUCTION
// At index 546 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (69) // <select_gtl_5F_expression_5F_parser_27>
, NONTERMINAL (68) // <select_gtl_5F_expression_5F_parser_26>
, END_PRODUCTION
// At index 551 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) // $@$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 555 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
, END_PRODUCTION
// At index 556 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) // $:=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 559 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) // $+=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 562 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) // $-=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 565 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) // $*=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 568 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) // $/=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 571 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) // $mod=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 574 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) // $<<=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 577 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) // $>>=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 580 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) // $&=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 583 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) // $|=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 586 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) // $^=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 589 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, END_PRODUCTION
// At index 590 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 148
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 592 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 148
, END_PRODUCTION
// At index 593 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 180
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) // $by$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (15) // <gtl_sorting_order>
, NONTERMINAL (73) // <select_gtl_5F_instruction_5F_parser_3>
, END_PRODUCTION
// At index 598 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 180
, NONTERMINAL (15) // <gtl_sorting_order>
, END_PRODUCTION
// At index 600 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 183
, END_PRODUCTION
// At index 601 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 183
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (15) // <gtl_sorting_order>
, NONTERMINAL (73) // <select_gtl_5F_instruction_5F_parser_3>
, END_PRODUCTION
// At index 606 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 237
, END_PRODUCTION
// At index 607 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 237
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (75) // <select_gtl_5F_instruction_5F_parser_5>
, END_PRODUCTION
// At index 611 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 240
, END_PRODUCTION
// At index 612 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 240
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (75) // <select_gtl_5F_instruction_5F_parser_5>
, END_PRODUCTION
// At index 616 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 260
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 618 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 260
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) // $<$
, END_PRODUCTION
// At index 620 : <>, in file '.ggs', line 0
, NONTERMINAL (6) // <gtl_start_symbol>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_gtl_grammar [209] = {
 {"<gtl_expression>", "gtl_expression_parser", 0}, // at index 0
 {"<gtl_variable>", "gtl_expression_parser", 3}, // at index 1
 {"<gtl_variable_or_here>", "gtl_expression_parser", 7}, // at index 2
 {"<gtl_import>", "gtl_instruction_parser", 9}, // at index 3
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 12}, // at index 4
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 16}, // at index 5
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 19}, // at index 6
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 24}, // at index 7
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 29}, // at index 8
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 32}, // at index 9
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 35}, // at index 10
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 38}, // at index 11
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 42}, // at index 12
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 45}, // at index 13
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 47}, // at index 14
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 49}, // at index 15
 {"<gtl_argument_list>", "gtl_expression_parser", 55}, // at index 16
 {"<gtl_start_symbol>", "gtl_parser", 59}, // at index 17
 {"<gtl_template_instruction_list>", "gtl_parser", 62}, // at index 18
 {"<gtl_template_instruction>", "gtl_parser", 64}, // at index 19
 {"<gtl_template_instruction>", "gtl_parser", 67}, // at index 20
 {"<gtl_template_instruction>", "gtl_parser", 76}, // at index 21
 {"<gtl_template_instruction>", "gtl_parser", 80}, // at index 22
 {"<gtl_template_instruction>", "gtl_parser", 83}, // at index 23
 {"<gtl_template_instruction>", "gtl_parser", 92}, // at index 24
 {"<gtl_template_instruction>", "gtl_parser", 106}, // at index 25
 {"<gtl_template_instruction>", "gtl_parser", 117}, // at index 26
 {"<gtl_template_instruction>", "gtl_parser", 133}, // at index 27
 {"<gtl_template_instruction>", "gtl_parser", 143}, // at index 28
 {"<gtl_file_name>", "gtl_parser", 146}, // at index 29
 {"<gtl_relation_term>", "gtl_expression_parser", 148}, // at index 30
 {"<gtl_relation_factor>", "gtl_expression_parser", 151}, // at index 31
 {"<gtl_simple_expression>", "gtl_expression_parser", 154}, // at index 32
 {"<gtl_term>", "gtl_expression_parser", 157}, // at index 33
 {"<gtl_factor>", "gtl_expression_parser", 160}, // at index 34
 {"<gtl_factor>", "gtl_expression_parser", 164}, // at index 35
 {"<gtl_factor>", "gtl_expression_parser", 167}, // at index 36
 {"<gtl_factor>", "gtl_expression_parser", 170}, // at index 37
 {"<gtl_factor>", "gtl_expression_parser", 173}, // at index 38
 {"<gtl_factor>", "gtl_expression_parser", 176}, // at index 39
 {"<gtl_factor>", "gtl_expression_parser", 178}, // at index 40
 {"<gtl_factor>", "gtl_expression_parser", 180}, // at index 41
 {"<gtl_factor>", "gtl_expression_parser", 182}, // at index 42
 {"<gtl_factor>", "gtl_expression_parser", 184}, // at index 43
 {"<gtl_factor>", "gtl_expression_parser", 186}, // at index 44
 {"<gtl_factor>", "gtl_expression_parser", 188}, // at index 45
 {"<gtl_factor>", "gtl_expression_parser", 194}, // at index 46
 {"<gtl_factor>", "gtl_expression_parser", 197}, // at index 47
 {"<gtl_factor>", "gtl_expression_parser", 201}, // at index 48
 {"<gtl_factor>", "gtl_expression_parser", 204}, // at index 49
 {"<gtl_factor>", "gtl_expression_parser", 206}, // at index 50
 {"<gtl_factor>", "gtl_expression_parser", 208}, // at index 51
 {"<gtl_factor>", "gtl_expression_parser", 210}, // at index 52
 {"<gtl_factor>", "gtl_expression_parser", 213}, // at index 53
 {"<gtl_factor>", "gtl_expression_parser", 215}, // at index 54
 {"<gtl_factor>", "gtl_expression_parser", 217}, // at index 55
 {"<gtl_factor>", "gtl_expression_parser", 221}, // at index 56
 {"<gtl_factor>", "gtl_expression_parser", 225}, // at index 57
 {"<gtl_factor>", "gtl_expression_parser", 229}, // at index 58
 {"<gtl_factor>", "gtl_expression_parser", 233}, // at index 59
 {"<gtl_factor>", "gtl_expression_parser", 237}, // at index 60
 {"<gtl_sorting_order>", "gtl_instruction_parser", 241}, // at index 61
 {"<select_gtl_5F_parser_0>", "gtl_parser", 243}, // at index 62
 {"<select_gtl_5F_parser_0>", "gtl_parser", 244}, // at index 63
 {"<select_gtl_5F_parser_1>", "gtl_parser", 247}, // at index 64
 {"<select_gtl_5F_parser_1>", "gtl_parser", 248}, // at index 65
 {"<select_gtl_5F_parser_1>", "gtl_parser", 251}, // at index 66
 {"<select_gtl_5F_parser_2>", "gtl_parser", 254}, // at index 67
 {"<select_gtl_5F_parser_2>", "gtl_parser", 256}, // at index 68
 {"<select_gtl_5F_parser_3>", "gtl_parser", 257}, // at index 69
 {"<select_gtl_5F_parser_3>", "gtl_parser", 261}, // at index 70
 {"<select_gtl_5F_parser_4>", "gtl_parser", 262}, // at index 71
 {"<select_gtl_5F_parser_4>", "gtl_parser", 265}, // at index 72
 {"<select_gtl_5F_parser_5>", "gtl_parser", 266}, // at index 73
 {"<select_gtl_5F_parser_5>", "gtl_parser", 267}, // at index 74
 {"<select_gtl_5F_parser_6>", "gtl_parser", 271}, // at index 75
 {"<select_gtl_5F_parser_6>", "gtl_parser", 277}, // at index 76
 {"<select_gtl_5F_parser_7>", "gtl_parser", 280}, // at index 77
 {"<select_gtl_5F_parser_7>", "gtl_parser", 283}, // at index 78
 {"<select_gtl_5F_parser_8>", "gtl_parser", 284}, // at index 79
 {"<select_gtl_5F_parser_8>", "gtl_parser", 289}, // at index 80
 {"<select_gtl_5F_parser_9>", "gtl_parser", 290}, // at index 81
 {"<select_gtl_5F_parser_9>", "gtl_parser", 293}, // at index 82
 {"<select_gtl_5F_parser_10>", "gtl_parser", 294}, // at index 83
 {"<select_gtl_5F_parser_10>", "gtl_parser", 295}, // at index 84
 {"<select_gtl_5F_parser_11>", "gtl_parser", 301}, // at index 85
 {"<select_gtl_5F_parser_11>", "gtl_parser", 304}, // at index 86
 {"<select_gtl_5F_parser_12>", "gtl_parser", 305}, // at index 87
 {"<select_gtl_5F_parser_12>", "gtl_parser", 308}, // at index 88
 {"<select_gtl_5F_parser_13>", "gtl_parser", 309}, // at index 89
 {"<select_gtl_5F_parser_13>", "gtl_parser", 313}, // at index 90
 {"<select_gtl_5F_parser_14>", "gtl_parser", 314}, // at index 91
 {"<select_gtl_5F_parser_14>", "gtl_parser", 317}, // at index 92
 {"<select_gtl_5F_parser_15>", "gtl_parser", 318}, // at index 93
 {"<select_gtl_5F_parser_15>", "gtl_parser", 321}, // at index 94
 {"<select_gtl_5F_parser_16>", "gtl_parser", 322}, // at index 95
 {"<select_gtl_5F_parser_16>", "gtl_parser", 325}, // at index 96
 {"<select_gtl_5F_parser_17>", "gtl_parser", 326}, // at index 97
 {"<select_gtl_5F_parser_17>", "gtl_parser", 327}, // at index 98
 {"<select_gtl_5F_parser_18>", "gtl_parser", 331}, // at index 99
 {"<select_gtl_5F_parser_18>", "gtl_parser", 334}, // at index 100
 {"<select_gtl_5F_parser_19>", "gtl_parser", 335}, // at index 101
 {"<select_gtl_5F_parser_19>", "gtl_parser", 336}, // at index 102
 {"<select_gtl_5F_parser_19>", "gtl_parser", 338}, // at index 103
 {"<select_gtl_5F_parser_20>", "gtl_parser", 340}, // at index 104
 {"<select_gtl_5F_parser_20>", "gtl_parser", 343}, // at index 105
 {"<select_gtl_5F_parser_21>", "gtl_parser", 344}, // at index 106
 {"<select_gtl_5F_parser_21>", "gtl_parser", 347}, // at index 107
 {"<select_gtl_5F_parser_22>", "gtl_parser", 348}, // at index 108
 {"<select_gtl_5F_parser_22>", "gtl_parser", 351}, // at index 109
 {"<select_gtl_5F_parser_23>", "gtl_parser", 352}, // at index 110
 {"<select_gtl_5F_parser_23>", "gtl_parser", 355}, // at index 111
 {"<select_gtl_5F_parser_24>", "gtl_parser", 356}, // at index 112
 {"<select_gtl_5F_parser_24>", "gtl_parser", 360}, // at index 113
 {"<select_gtl_5F_parser_25>", "gtl_parser", 361}, // at index 114
 {"<select_gtl_5F_parser_25>", "gtl_parser", 363}, // at index 115
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 366}, // at index 116
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 367}, // at index 117
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 371}, // at index 118
 {"<select_gtl_5F_expression_5F_parser_1>", "gtl_expression_parser", 375}, // at index 119
 {"<select_gtl_5F_expression_5F_parser_1>", "gtl_expression_parser", 376}, // at index 120
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 380}, // at index 121
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 381}, // at index 122
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 384}, // at index 123
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 387}, // at index 124
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 390}, // at index 125
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 393}, // at index 126
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 396}, // at index 127
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 399}, // at index 128
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 400}, // at index 129
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 404}, // at index 130
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 408}, // at index 131
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 412}, // at index 132
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 416}, // at index 133
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 420}, // at index 134
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 421}, // at index 135
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 425}, // at index 136
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 429}, // at index 137
 {"<select_gtl_5F_expression_5F_parser_5>", "gtl_expression_parser", 433}, // at index 138
 {"<select_gtl_5F_expression_5F_parser_5>", "gtl_expression_parser", 434}, // at index 139
 {"<select_gtl_5F_expression_5F_parser_6>", "gtl_expression_parser", 438}, // at index 140
 {"<select_gtl_5F_expression_5F_parser_6>", "gtl_expression_parser", 439}, // at index 141
 {"<select_gtl_5F_expression_5F_parser_7>", "gtl_expression_parser", 443}, // at index 142
 {"<select_gtl_5F_expression_5F_parser_7>", "gtl_expression_parser", 444}, // at index 143
 {"<select_gtl_5F_expression_5F_parser_8>", "gtl_expression_parser", 448}, // at index 144
 {"<select_gtl_5F_expression_5F_parser_8>", "gtl_expression_parser", 451}, // at index 145
 {"<select_gtl_5F_expression_5F_parser_9>", "gtl_expression_parser", 452}, // at index 146
 {"<select_gtl_5F_expression_5F_parser_9>", "gtl_expression_parser", 453}, // at index 147
 {"<select_gtl_5F_expression_5F_parser_10>", "gtl_expression_parser", 457}, // at index 148
 {"<select_gtl_5F_expression_5F_parser_10>", "gtl_expression_parser", 462}, // at index 149
 {"<select_gtl_5F_expression_5F_parser_11>", "gtl_expression_parser", 463}, // at index 150
 {"<select_gtl_5F_expression_5F_parser_11>", "gtl_expression_parser", 466}, // at index 151
 {"<select_gtl_5F_expression_5F_parser_12>", "gtl_expression_parser", 468}, // at index 152
 {"<select_gtl_5F_expression_5F_parser_12>", "gtl_expression_parser", 471}, // at index 153
 {"<select_gtl_5F_expression_5F_parser_13>", "gtl_expression_parser", 472}, // at index 154
 {"<select_gtl_5F_expression_5F_parser_13>", "gtl_expression_parser", 473}, // at index 155
 {"<select_gtl_5F_expression_5F_parser_14>", "gtl_expression_parser", 477}, // at index 156
 {"<select_gtl_5F_expression_5F_parser_14>", "gtl_expression_parser", 482}, // at index 157
 {"<select_gtl_5F_expression_5F_parser_15>", "gtl_expression_parser", 483}, // at index 158
 {"<select_gtl_5F_expression_5F_parser_15>", "gtl_expression_parser", 484}, // at index 159
 {"<select_gtl_5F_expression_5F_parser_16>", "gtl_expression_parser", 490}, // at index 160
 {"<select_gtl_5F_expression_5F_parser_16>", "gtl_expression_parser", 495}, // at index 161
 {"<select_gtl_5F_expression_5F_parser_17>", "gtl_expression_parser", 496}, // at index 162
 {"<select_gtl_5F_expression_5F_parser_17>", "gtl_expression_parser", 497}, // at index 163
 {"<select_gtl_5F_expression_5F_parser_18>", "gtl_expression_parser", 503}, // at index 164
 {"<select_gtl_5F_expression_5F_parser_18>", "gtl_expression_parser", 506}, // at index 165
 {"<select_gtl_5F_expression_5F_parser_19>", "gtl_expression_parser", 507}, // at index 166
 {"<select_gtl_5F_expression_5F_parser_19>", "gtl_expression_parser", 508}, // at index 167
 {"<select_gtl_5F_expression_5F_parser_20>", "gtl_expression_parser", 512}, // at index 168
 {"<select_gtl_5F_expression_5F_parser_20>", "gtl_expression_parser", 513}, // at index 169
 {"<select_gtl_5F_expression_5F_parser_21>", "gtl_expression_parser", 518}, // at index 170
 {"<select_gtl_5F_expression_5F_parser_21>", "gtl_expression_parser", 523}, // at index 171
 {"<select_gtl_5F_expression_5F_parser_22>", "gtl_expression_parser", 524}, // at index 172
 {"<select_gtl_5F_expression_5F_parser_22>", "gtl_expression_parser", 529}, // at index 173
 {"<select_gtl_5F_expression_5F_parser_23>", "gtl_expression_parser", 530}, // at index 174
 {"<select_gtl_5F_expression_5F_parser_23>", "gtl_expression_parser", 531}, // at index 175
 {"<select_gtl_5F_expression_5F_parser_24>", "gtl_expression_parser", 536}, // at index 176
 {"<select_gtl_5F_expression_5F_parser_24>", "gtl_expression_parser", 538}, // at index 177
 {"<select_gtl_5F_expression_5F_parser_25>", "gtl_expression_parser", 540}, // at index 178
 {"<select_gtl_5F_expression_5F_parser_25>", "gtl_expression_parser", 544}, // at index 179
 {"<select_gtl_5F_expression_5F_parser_26>", "gtl_expression_parser", 545}, // at index 180
 {"<select_gtl_5F_expression_5F_parser_26>", "gtl_expression_parser", 546}, // at index 181
 {"<select_gtl_5F_expression_5F_parser_27>", "gtl_expression_parser", 551}, // at index 182
 {"<select_gtl_5F_expression_5F_parser_27>", "gtl_expression_parser", 555}, // at index 183
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 556}, // at index 184
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 559}, // at index 185
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 562}, // at index 186
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 565}, // at index 187
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 568}, // at index 188
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 571}, // at index 189
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 574}, // at index 190
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 577}, // at index 191
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 580}, // at index 192
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 583}, // at index 193
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 586}, // at index 194
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 589}, // at index 195
 {"<select_gtl_5F_instruction_5F_parser_1>", "gtl_instruction_parser", 590}, // at index 196
 {"<select_gtl_5F_instruction_5F_parser_1>", "gtl_instruction_parser", 592}, // at index 197
 {"<select_gtl_5F_instruction_5F_parser_2>", "gtl_instruction_parser", 593}, // at index 198
 {"<select_gtl_5F_instruction_5F_parser_2>", "gtl_instruction_parser", 598}, // at index 199
 {"<select_gtl_5F_instruction_5F_parser_3>", "gtl_instruction_parser", 600}, // at index 200
 {"<select_gtl_5F_instruction_5F_parser_3>", "gtl_instruction_parser", 601}, // at index 201
 {"<select_gtl_5F_instruction_5F_parser_4>", "gtl_instruction_parser", 606}, // at index 202
 {"<select_gtl_5F_instruction_5F_parser_4>", "gtl_instruction_parser", 607}, // at index 203
 {"<select_gtl_5F_instruction_5F_parser_5>", "gtl_instruction_parser", 611}, // at index 204
 {"<select_gtl_5F_instruction_5F_parser_5>", "gtl_instruction_parser", 612}, // at index 205
 {"<select_gtl_5F_instruction_5F_parser_6>", "gtl_instruction_parser", 616}, // at index 206
 {"<select_gtl_5F_instruction_5F_parser_6>", "gtl_instruction_parser", 618}, // at index 207
 {"<>", "", 620} // at index 208
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_gtl_grammar [209] = {
0, // index 0 : <gtl_expression>, in file 'gtl_expression_parser.ggs', line 33
3, // index 1 : <gtl_variable>, in file 'gtl_expression_parser.ggs', line 667
7, // index 2 : <gtl_variable_or_here>, in file 'gtl_expression_parser.ggs', line 702
9, // index 3 : <gtl_import>, in file 'gtl_instruction_parser.ggs', line 270
12, // index 4 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 40
16, // index 5 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 95
19, // index 6 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 104
24, // index 7 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 118
29, // index 8 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 132
32, // index 9 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 144
35, // index 10 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 163
38, // index 11 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 175
42, // index 12 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 202
45, // index 13 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 214
47, // index 14 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 222
49, // index 15 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 230
55, // index 16 : <gtl_argument_list>, in file 'gtl_expression_parser.ggs', line 716
59, // index 17 : <gtl_start_symbol>, in file 'gtl_parser.ggs', line 50
62, // index 18 : <gtl_template_instruction_list>, in file 'gtl_parser.ggs', line 63
64, // index 19 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 86
67, // index 20 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 100
76, // index 21 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 116
80, // index 22 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 170
83, // index 23 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 181
92, // index 24 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 211
106, // index 25 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 271
117, // index 26 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 308
133, // index 27 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 365
143, // index 28 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 393
146, // index 29 : <gtl_file_name>, in file 'gtl_parser.ggs', line 404
148, // index 30 : <gtl_relation_term>, in file 'gtl_expression_parser.ggs', line 53
151, // index 31 : <gtl_relation_factor>, in file 'gtl_expression_parser.ggs', line 69
154, // index 32 : <gtl_simple_expression>, in file 'gtl_expression_parser.ggs', line 117
157, // index 33 : <gtl_term>, in file 'gtl_expression_parser.ggs', line 162
160, // index 34 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 192
164, // index 35 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 208
167, // index 36 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 220
170, // index 37 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 232
173, // index 38 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 244
176, // index 39 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 256
178, // index 40 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 269
180, // index 41 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 282
182, // index 42 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 295
184, // index 43 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 308
186, // index 44 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 321
188, // index 45 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 335
194, // index 46 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 369
197, // index 47 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 401
201, // index 48 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 420
204, // index 49 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 429
206, // index 50 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 445
208, // index 51 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 461
210, // index 52 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 477
213, // index 53 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 514
215, // index 54 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 533
217, // index 55 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 552
221, // index 56 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 576
225, // index 57 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 587
229, // index 58 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 606
233, // index 59 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 627
237, // index 60 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 648
241, // index 61 : <gtl_sorting_order>, in file 'gtl_instruction_parser.ggs', line 257
243, // index 62 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
244, // index 63 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
247, // index 64 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
248, // index 65 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
251, // index 66 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
254, // index 67 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 104
256, // index 68 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 104
257, // index 69 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 126
261, // index 70 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 126
262, // index 71 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 129
265, // index 72 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 129
266, // index 73 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 130
267, // index 74 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 130
271, // index 75 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 140
277, // index 76 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 140
280, // index 77 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 144
283, // index 78 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 144
284, // index 79 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 147
289, // index 80 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 147
290, // index 81 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 154
293, // index 82 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 154
294, // index 83 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 187
295, // index 84 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 187
301, // index 85 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 197
304, // index 86 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 197
305, // index 87 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 222
308, // index 88 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 222
309, // index 89 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 228
313, // index 90 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 228
314, // index 91 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 236
317, // index 92 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 236
318, // index 93 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 244
321, // index 94 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 244
322, // index 95 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 249
325, // index 96 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 249
326, // index 97 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 284
327, // index 98 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 284
331, // index 99 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 294
334, // index 100 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 294
335, // index 101 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 324
336, // index 102 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 324
338, // index 103 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 324
340, // index 104 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 332
343, // index 105 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 332
344, // index 106 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 337
347, // index 107 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 337
348, // index 108 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 345
351, // index 109 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 345
352, // index 110 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 350
355, // index 111 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 350
356, // index 112 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 370
360, // index 113 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 370
361, // index 114 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 407
363, // index 115 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 407
366, // index 116 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
367, // index 117 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
371, // index 118 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
375, // index 119 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
376, // index 120 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
380, // index 121 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
381, // index 122 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
384, // index 123 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
387, // index 124 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
390, // index 125 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
393, // index 126 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
396, // index 127 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
399, // index 128 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
400, // index 129 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
404, // index 130 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
408, // index 131 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
412, // index 132 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
416, // index 133 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
420, // index 134 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
421, // index 135 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
425, // index 136 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
429, // index 137 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
433, // index 138 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
434, // index 139 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
438, // index 140 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
439, // index 141 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
443, // index 142 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
444, // index 143 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
448, // index 144 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
451, // index 145 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
452, // index 146 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
453, // index 147 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
457, // index 148 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
462, // index 149 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
463, // index 150 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
466, // index 151 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
468, // index 152 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
471, // index 153 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
472, // index 154 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
473, // index 155 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
477, // index 156 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
482, // index 157 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
483, // index 158 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
484, // index 159 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
490, // index 160 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
495, // index 161 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
496, // index 162 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
497, // index 163 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
503, // index 164 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
506, // index 165 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
507, // index 166 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
508, // index 167 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
512, // index 168 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
513, // index 169 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
518, // index 170 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
523, // index 171 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
524, // index 172 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
529, // index 173 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
530, // index 174 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
531, // index 175 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
536, // index 176 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
538, // index 177 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
540, // index 178 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
544, // index 179 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
545, // index 180 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
546, // index 181 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
551, // index 182 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
555, // index 183 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
556, // index 184 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
559, // index 185 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
562, // index 186 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
565, // index 187 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
568, // index 188 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
571, // index 189 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
574, // index 190 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
577, // index 191 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
580, // index 192 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
583, // index 193 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
586, // index 194 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
589, // index 195 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
590, // index 196 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 148
592, // index 197 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 148
593, // index 198 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 180
598, // index 199 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 180
600, // index 200 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 183
601, // index 201 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 183
606, // index 202 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 237
607, // index 203 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 237
611, // index 204 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 240
612, // index 205 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 240
616, // index 206 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 260
618, // index 207 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 260
620 // index 208 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_gtl_grammar [79] = {
0, // at 0 : <gtl_expression>
1, // at 1 : <gtl_variable>
2, // at 2 : <gtl_variable_or_here>
3, // at 3 : <gtl_import>
4, // at 4 : <gtl_simple_instruction>
16, // at 5 : <gtl_argument_list>
17, // at 6 : <gtl_start_symbol>
18, // at 7 : <gtl_template_instruction_list>
19, // at 8 : <gtl_template_instruction>
29, // at 9 : <gtl_file_name>
30, // at 10 : <gtl_relation_term>
31, // at 11 : <gtl_relation_factor>
32, // at 12 : <gtl_simple_expression>
33, // at 13 : <gtl_term>
34, // at 14 : <gtl_factor>
61, // at 15 : <gtl_sorting_order>
62, // at 16 : <select_gtl_5F_parser_0>
64, // at 17 : <select_gtl_5F_parser_1>
67, // at 18 : <select_gtl_5F_parser_2>
69, // at 19 : <select_gtl_5F_parser_3>
71, // at 20 : <select_gtl_5F_parser_4>
73, // at 21 : <select_gtl_5F_parser_5>
75, // at 22 : <select_gtl_5F_parser_6>
77, // at 23 : <select_gtl_5F_parser_7>
79, // at 24 : <select_gtl_5F_parser_8>
81, // at 25 : <select_gtl_5F_parser_9>
83, // at 26 : <select_gtl_5F_parser_10>
85, // at 27 : <select_gtl_5F_parser_11>
87, // at 28 : <select_gtl_5F_parser_12>
89, // at 29 : <select_gtl_5F_parser_13>
91, // at 30 : <select_gtl_5F_parser_14>
93, // at 31 : <select_gtl_5F_parser_15>
95, // at 32 : <select_gtl_5F_parser_16>
97, // at 33 : <select_gtl_5F_parser_17>
99, // at 34 : <select_gtl_5F_parser_18>
101, // at 35 : <select_gtl_5F_parser_19>
104, // at 36 : <select_gtl_5F_parser_20>
106, // at 37 : <select_gtl_5F_parser_21>
108, // at 38 : <select_gtl_5F_parser_22>
110, // at 39 : <select_gtl_5F_parser_23>
112, // at 40 : <select_gtl_5F_parser_24>
114, // at 41 : <select_gtl_5F_parser_25>
116, // at 42 : <select_gtl_5F_expression_5F_parser_0>
119, // at 43 : <select_gtl_5F_expression_5F_parser_1>
121, // at 44 : <select_gtl_5F_expression_5F_parser_2>
128, // at 45 : <select_gtl_5F_expression_5F_parser_3>
134, // at 46 : <select_gtl_5F_expression_5F_parser_4>
138, // at 47 : <select_gtl_5F_expression_5F_parser_5>
140, // at 48 : <select_gtl_5F_expression_5F_parser_6>
142, // at 49 : <select_gtl_5F_expression_5F_parser_7>
144, // at 50 : <select_gtl_5F_expression_5F_parser_8>
146, // at 51 : <select_gtl_5F_expression_5F_parser_9>
148, // at 52 : <select_gtl_5F_expression_5F_parser_10>
150, // at 53 : <select_gtl_5F_expression_5F_parser_11>
152, // at 54 : <select_gtl_5F_expression_5F_parser_12>
154, // at 55 : <select_gtl_5F_expression_5F_parser_13>
156, // at 56 : <select_gtl_5F_expression_5F_parser_14>
158, // at 57 : <select_gtl_5F_expression_5F_parser_15>
160, // at 58 : <select_gtl_5F_expression_5F_parser_16>
162, // at 59 : <select_gtl_5F_expression_5F_parser_17>
164, // at 60 : <select_gtl_5F_expression_5F_parser_18>
166, // at 61 : <select_gtl_5F_expression_5F_parser_19>
168, // at 62 : <select_gtl_5F_expression_5F_parser_20>
170, // at 63 : <select_gtl_5F_expression_5F_parser_21>
172, // at 64 : <select_gtl_5F_expression_5F_parser_22>
174, // at 65 : <select_gtl_5F_expression_5F_parser_23>
176, // at 66 : <select_gtl_5F_expression_5F_parser_24>
178, // at 67 : <select_gtl_5F_expression_5F_parser_25>
180, // at 68 : <select_gtl_5F_expression_5F_parser_26>
182, // at 69 : <select_gtl_5F_expression_5F_parser_27>
184, // at 70 : <select_gtl_5F_instruction_5F_parser_0>
196, // at 71 : <select_gtl_5F_instruction_5F_parser_1>
198, // at 72 : <select_gtl_5F_instruction_5F_parser_2>
200, // at 73 : <select_gtl_5F_instruction_5F_parser_3>
202, // at 74 : <select_gtl_5F_instruction_5F_parser_4>
204, // at 75 : <select_gtl_5F_instruction_5F_parser_5>
206, // at 76 : <select_gtl_5F_instruction_5F_parser_6>
208, // at 77 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_gtl_grammar [] = {
// At index 0 : <gtl_expression> only one production, no choice
  -1,
// At index 1 : <gtl_variable> only one production, no choice
  -1,
// At index 2 : <gtl_variable_or_here> only one production, no choice
  -1,
// At index 3 : <gtl_import> only one production, no choice
  -1,
// At index 4 : <gtl_simple_instruction>
C_Lexique_gtl_5F_scanner::kToken_let, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_unlet, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_error, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken_warning, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken_print, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_println, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken_display, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken_sort, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken_tab, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken_variables, -1, // Choice 10
C_Lexique_gtl_5F_scanner::kToken_libraries, -1, // Choice 11
C_Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 12
  -1,
// At index 29 : <gtl_argument_list> only one production, no choice
  -1,
// At index 30 : <gtl_start_symbol> only one production, no choice
  -1,
// At index 31 : <gtl_template_instruction_list> only one production, no choice
  -1,
// At index 32 : <gtl_template_instruction>
C_Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_write, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_template, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__3F_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken_if, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_foreach, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken_for, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken_loop, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken_repeat, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken_input, -1, // Choice 10
  -1,
// At index 53 : <gtl_file_name> only one production, no choice
  -1,
// At index 54 : <gtl_relation_term> only one production, no choice
  -1,
// At index 55 : <gtl_relation_factor> only one production, no choice
  -1,
// At index 56 : <gtl_simple_expression> only one production, no choice
  -1,
// At index 57 : <gtl_term> only one production, no choice
  -1,
// At index 58 : <gtl_factor>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_not, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__7E_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2B_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_yes, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken_no, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken_string, -1, // Choice 10
C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, -1, // Choice 11
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 12
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 13
C_Lexique_gtl_5F_scanner::kToken_exists, -1, // Choice 14
C_Lexique_gtl_5F_scanner::kToken_typeof, -1, // Choice 15
C_Lexique_gtl_5F_scanner::kToken_true, -1, // Choice 16
C_Lexique_gtl_5F_scanner::kToken_false, -1, // Choice 17
C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, -1, // Choice 18
C_Lexique_gtl_5F_scanner::kToken__40_, -1, // Choice 19
C_Lexique_gtl_5F_scanner::kToken_emptylist, -1, // Choice 20
C_Lexique_gtl_5F_scanner::kToken_emptymap, -1, // Choice 21
C_Lexique_gtl_5F_scanner::kToken_mapof, -1, // Choice 22
C_Lexique_gtl_5F_scanner::kToken_listof, -1, // Choice 23
C_Lexique_gtl_5F_scanner::kToken__40__28_, -1, // Choice 24
C_Lexique_gtl_5F_scanner::kToken__40__5B_, -1, // Choice 25
C_Lexique_gtl_5F_scanner::kToken__40__7B_, -1, // Choice 26
C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 27
  -1,
// At index 113 : <gtl_sorting_order> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 114 : <select_gtl_5F_parser_0>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_import, -1, // Choice 2
  -1,
// At index 141 : <select_gtl_5F_parser_1>
C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_input, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 3
  -1,
// At index 175 : <select_gtl_5F_parser_2>
C_Lexique_gtl_5F_scanner::kToken_executable, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 2
  -1,
// At index 206 : <select_gtl_5F_parser_3>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 213 : <select_gtl_5F_parser_4>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 244 : <select_gtl_5F_parser_5>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 249 : <select_gtl_5F_parser_6>
C_Lexique_gtl_5F_scanner::kToken_if, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 255 : <select_gtl_5F_parser_7>
C_Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 290 : <select_gtl_5F_parser_8>
C_Lexique_gtl_5F_scanner::kToken_or, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 324 : <select_gtl_5F_parser_9>
C_Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 358 : <select_gtl_5F_parser_10>
C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_else, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_elsif, -1, // Choice 2
  -1,
// At index 364 : <select_gtl_5F_parser_11>
C_Lexique_gtl_5F_scanner::kToken_else, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 369 : <select_gtl_5F_parser_12>
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 2
  -1,
// At index 375 : <select_gtl_5F_parser_13>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 2
  -1,
// At index 380 : <select_gtl_5F_parser_14>
C_Lexique_gtl_5F_scanner::kToken_before, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 385 : <select_gtl_5F_parser_15>
C_Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 2
  -1,
// At index 391 : <select_gtl_5F_parser_16>
C_Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 396 : <select_gtl_5F_parser_17>
C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 401 : <select_gtl_5F_parser_18>
C_Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 406 : <select_gtl_5F_parser_19>
C_Lexique_gtl_5F_scanner::kToken_to, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_up, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_down, -1, // Choice 3
  -1,
// At index 413 : <select_gtl_5F_parser_20>
C_Lexique_gtl_5F_scanner::kToken_step, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 419 : <select_gtl_5F_parser_21>
C_Lexique_gtl_5F_scanner::kToken_before, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 424 : <select_gtl_5F_parser_22>
C_Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 2
  -1,
// At index 430 : <select_gtl_5F_parser_23>
C_Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 435 : <select_gtl_5F_parser_24>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 2
  -1,
// At index 462 : <select_gtl_5F_parser_25>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 467 : <select_gtl_5F_expression_5F_parser_0>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__7C_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__5E_, -1, // Choice 3
  -1,
// At index 518 : <select_gtl_5F_expression_5F_parser_1>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__26_, -1, // Choice 2
  -1,
// At index 569 : <select_gtl_5F_expression_5F_parser_2>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3D__3D_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__21__3D_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__3C__3D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__3E__3D_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken__3E_, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 7
  -1,
// At index 631 : <select_gtl_5F_expression_5F_parser_3>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3C__3C_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__3E__3E_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2B_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2E_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken__2D_, -1, // Choice 6
  -1,
// At index 697 : <select_gtl_5F_expression_5F_parser_4>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2A_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__2F_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken_mod, -1, // Choice 4
  -1,
// At index 764 : <select_gtl_5F_expression_5F_parser_5>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 769 : <select_gtl_5F_expression_5F_parser_6>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 774 : <select_gtl_5F_expression_5F_parser_7>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 2
  -1,
// At index 840 : <select_gtl_5F_expression_5F_parser_8>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 871 : <select_gtl_5F_expression_5F_parser_9>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 876 : <select_gtl_5F_expression_5F_parser_10>
C_Lexique_gtl_5F_scanner::kToken_default, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 942 : <select_gtl_5F_expression_5F_parser_11>
C_Lexique_gtl_5F_scanner::kToken_by, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 947 : <select_gtl_5F_expression_5F_parser_12>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 978 : <select_gtl_5F_expression_5F_parser_13>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 983 : <select_gtl_5F_expression_5F_parser_14>
C_Lexique_gtl_5F_scanner::kToken_string, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 2
  -1,
// At index 988 : <select_gtl_5F_expression_5F_parser_15>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 993 : <select_gtl_5F_expression_5F_parser_16>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__7D_, -1, // Choice 2
  -1,
// At index 998 : <select_gtl_5F_expression_5F_parser_17>
C_Lexique_gtl_5F_scanner::kToken__7D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1003 : <select_gtl_5F_expression_5F_parser_18>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 2
  -1,
// At index 1034 : <select_gtl_5F_expression_5F_parser_19>
C_Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1039 : <select_gtl_5F_expression_5F_parser_20>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3A__3A_, -1, // Choice 2
  -1,
// At index 1118 : <select_gtl_5F_expression_5F_parser_21>
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1198 : <select_gtl_5F_expression_5F_parser_22>
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1278 : <select_gtl_5F_expression_5F_parser_23>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 2
  -1,
// At index 1358 : <select_gtl_5F_expression_5F_parser_24>
C_Lexique_gtl_5F_scanner::kToken_here, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 2
  -1,
// At index 1363 : <select_gtl_5F_expression_5F_parser_25>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 1368 : <select_gtl_5F_expression_5F_parser_26>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1373 : <select_gtl_5F_expression_5F_parser_27>
C_Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 1379 : <select_gtl_5F_instruction_5F_parser_0>
C_Lexique_gtl_5F_scanner::kToken__3A__3D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2B__3D_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__2D__3D_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2A__3D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2F__3D_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_mod_3D_, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken__26__3D_, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken__7C__3D_, -1, // Choice 10
C_Lexique_gtl_5F_scanner::kToken__5E__3D_, -1, // Choice 11
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 12
  -1,
// At index 1433 : <select_gtl_5F_instruction_5F_parser_1>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1493 : <select_gtl_5F_instruction_5F_parser_2>
C_Lexique_gtl_5F_scanner::kToken_by, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
// At index 1499 : <select_gtl_5F_instruction_5F_parser_3>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1533 : <select_gtl_5F_instruction_5F_parser_4>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 1538 : <select_gtl_5F_instruction_5F_parser_5>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1543 : <select_gtl_5F_instruction_5F_parser_6>
C_Lexique_gtl_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
// At index 1548 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_gtl_grammar [79] = {
0, // at 0 : <gtl_expression>
1, // at 1 : <gtl_variable>
2, // at 2 : <gtl_variable_or_here>
3, // at 3 : <gtl_import>
4, // at 4 : <gtl_simple_instruction>
29, // at 5 : <gtl_argument_list>
30, // at 6 : <gtl_start_symbol>
31, // at 7 : <gtl_template_instruction_list>
32, // at 8 : <gtl_template_instruction>
53, // at 9 : <gtl_file_name>
54, // at 10 : <gtl_relation_term>
55, // at 11 : <gtl_relation_factor>
56, // at 12 : <gtl_simple_expression>
57, // at 13 : <gtl_term>
58, // at 14 : <gtl_factor>
113, // at 15 : <gtl_sorting_order>
114, // at 16 : <select_gtl_5F_parser_0>
141, // at 17 : <select_gtl_5F_parser_1>
175, // at 18 : <select_gtl_5F_parser_2>
206, // at 19 : <select_gtl_5F_parser_3>
213, // at 20 : <select_gtl_5F_parser_4>
244, // at 21 : <select_gtl_5F_parser_5>
249, // at 22 : <select_gtl_5F_parser_6>
255, // at 23 : <select_gtl_5F_parser_7>
290, // at 24 : <select_gtl_5F_parser_8>
324, // at 25 : <select_gtl_5F_parser_9>
358, // at 26 : <select_gtl_5F_parser_10>
364, // at 27 : <select_gtl_5F_parser_11>
369, // at 28 : <select_gtl_5F_parser_12>
375, // at 29 : <select_gtl_5F_parser_13>
380, // at 30 : <select_gtl_5F_parser_14>
385, // at 31 : <select_gtl_5F_parser_15>
391, // at 32 : <select_gtl_5F_parser_16>
396, // at 33 : <select_gtl_5F_parser_17>
401, // at 34 : <select_gtl_5F_parser_18>
406, // at 35 : <select_gtl_5F_parser_19>
413, // at 36 : <select_gtl_5F_parser_20>
419, // at 37 : <select_gtl_5F_parser_21>
424, // at 38 : <select_gtl_5F_parser_22>
430, // at 39 : <select_gtl_5F_parser_23>
435, // at 40 : <select_gtl_5F_parser_24>
462, // at 41 : <select_gtl_5F_parser_25>
467, // at 42 : <select_gtl_5F_expression_5F_parser_0>
518, // at 43 : <select_gtl_5F_expression_5F_parser_1>
569, // at 44 : <select_gtl_5F_expression_5F_parser_2>
631, // at 45 : <select_gtl_5F_expression_5F_parser_3>
697, // at 46 : <select_gtl_5F_expression_5F_parser_4>
764, // at 47 : <select_gtl_5F_expression_5F_parser_5>
769, // at 48 : <select_gtl_5F_expression_5F_parser_6>
774, // at 49 : <select_gtl_5F_expression_5F_parser_7>
840, // at 50 : <select_gtl_5F_expression_5F_parser_8>
871, // at 51 : <select_gtl_5F_expression_5F_parser_9>
876, // at 52 : <select_gtl_5F_expression_5F_parser_10>
942, // at 53 : <select_gtl_5F_expression_5F_parser_11>
947, // at 54 : <select_gtl_5F_expression_5F_parser_12>
978, // at 55 : <select_gtl_5F_expression_5F_parser_13>
983, // at 56 : <select_gtl_5F_expression_5F_parser_14>
988, // at 57 : <select_gtl_5F_expression_5F_parser_15>
993, // at 58 : <select_gtl_5F_expression_5F_parser_16>
998, // at 59 : <select_gtl_5F_expression_5F_parser_17>
1003, // at 60 : <select_gtl_5F_expression_5F_parser_18>
1034, // at 61 : <select_gtl_5F_expression_5F_parser_19>
1039, // at 62 : <select_gtl_5F_expression_5F_parser_20>
1118, // at 63 : <select_gtl_5F_expression_5F_parser_21>
1198, // at 64 : <select_gtl_5F_expression_5F_parser_22>
1278, // at 65 : <select_gtl_5F_expression_5F_parser_23>
1358, // at 66 : <select_gtl_5F_expression_5F_parser_24>
1363, // at 67 : <select_gtl_5F_expression_5F_parser_25>
1368, // at 68 : <select_gtl_5F_expression_5F_parser_26>
1373, // at 69 : <select_gtl_5F_expression_5F_parser_27>
1379, // at 70 : <select_gtl_5F_instruction_5F_parser_0>
1433, // at 71 : <select_gtl_5F_instruction_5F_parser_1>
1493, // at 72 : <select_gtl_5F_instruction_5F_parser_2>
1499, // at 73 : <select_gtl_5F_instruction_5F_parser_3>
1533, // at 74 : <select_gtl_5F_instruction_5F_parser_4>
1538, // at 75 : <select_gtl_5F_instruction_5F_parser_5>
1543, // at 76 : <select_gtl_5F_instruction_5F_parser_6>
1548, // at 77 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'gtl_expression' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_expression_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'gtl_variable' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_ (GALGAS_gtlVarPath & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'gtl_variable_or_here' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_ (GALGAS_gtlVarPath & parameter_1,
                                GALGAS_bool & parameter_2,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'gtl_import' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_import_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_import_ (GALGAS_gtlContext parameter_1,
                                GALGAS_library & parameter_2,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'gtl_simple_instruction' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_instruction_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_parse(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_parse(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_instruction_ (GALGAS_gtlInstruction & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_(parameter_1, inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_(parameter_1, inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'gtl_argument_list' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_argument_5F_list_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_argument_5F_list_ (GALGAS_gtlArgumentList & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'gtl_start_symbol' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_start_5F_symbol_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_start_5F_symbol_ (GALGAS_gtlContext parameter_1,
                                GALGAS_library & parameter_2,
                                GALGAS_gtlInstructionList & parameter_3,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

void cGrammar_gtl_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_gtl_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_gtl_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_gtl_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_gtl_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                    gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 620) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_gtlContext  parameter_1,
                                GALGAS_library &  parameter_2,
                                GALGAS_gtlInstructionList &  parameter_3
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_gtl_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                                      gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 620) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_gtl_5F_grammar grammar ;
        grammar.nt_gtl_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_gtlContext  parameter_1,
                                GALGAS_library &  parameter_2,
                                GALGAS_gtlInstructionList &  parameter_3
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_gtl_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                                    gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 620) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_gtl_5F_grammar grammar ;
      grammar.nt_gtl_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'gtl_template_instruction_list' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_5F_list_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_5F_list_ (GALGAS_gtlInstructionList & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'gtl_template_instruction' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_ (GALGAS_gtlInstruction & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'gtl_file_name' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_file_5F_name_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_file_5F_name_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'gtl_relation_term' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_term_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'gtl_relation_factor' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_factor_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'gtl_simple_expression' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_expression_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'gtl_term' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_term_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'gtl_factor' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_factor_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_parse(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_parse(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_parse(inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_parse(inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_parse(inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_parse(inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_parse(inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_parse(inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_parse(inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_parse(inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_parse(inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_parse(inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_parse(inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_parse(inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_parse(inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_parse(inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_parse(inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_(parameter_1, inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_(parameter_1, inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_(parameter_1, inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_(parameter_1, inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_(parameter_1, inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_(parameter_1, inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_(parameter_1, inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_(parameter_1, inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_(parameter_1, inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_(parameter_1, inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_(parameter_1, inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_(parameter_1, inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_(parameter_1, inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_(parameter_1, inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_(parameter_1, inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_(parameter_1, inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_(parameter_1, inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'gtl_sorting_order' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_sorting_5F_order_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_sorting_5F_order_ (GALGAS_lsint & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_0 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_1 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_2 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_3 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_4 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_5 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_6 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_7 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_8 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_9 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_10' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_10 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_11' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_11 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_12' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_12 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_13' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_13 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_14' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_14 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_15' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_15 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_16' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_16 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_17' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_17 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_18' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_18 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_19' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_19 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_20' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_20 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_21' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_21 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_22' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_22 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_23' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_23 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_24' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_24 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_25' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_25 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_0' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_0 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_1' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_1 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_2' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_2 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_3' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_3 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_4' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_4 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_5' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_5 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_6' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_6 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_7' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_7 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_8' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_8 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_9' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_9 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_10' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_10 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_11' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_11 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_12' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_12 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_13' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_13 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_14' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_14 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_15' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_15 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_16' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_16 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_17' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_17 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_18' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_18 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_19' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_19 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_20' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_20 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_21' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_21 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_22' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_22 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_23' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_23 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_24' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_24 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_25' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_25 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_26' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_26 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_27' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_27 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_0' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_0 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_1' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_1 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_2' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_2 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_3' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_3 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_4' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_4 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_5' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_5 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_6' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_6 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
