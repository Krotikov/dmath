#include "set.h"

univ_t* InitUniv() {
  univ_t* univ = new univ_t;
  univ->head = nullptr;

  return univ;
}

set_t* InitSet(std::string setName) {
  set_t* set = new set_t;
  if (set == nullptr)
    return nullptr;

  set->head = nullptr;
  set->next = nullptr;
  set->prev = nullptr;
  set->setName = setName;

  return set;
}

elem_t* InitElem(std::string elemName) {
  elem_t* elem = new elem_t;
  if (elem == nullptr)
    return nullptr;

  elem->next = nullptr;
  elem->prev = nullptr;
  elem->elemName = elemName;

  return elem;
}

ERR_STATUS SetDeletePtr(set_t* set) {
  if (set == nullptr)
    return ERROR;

  elem_t* head = set->head;
  elem_t* tmp = nullptr;

  while (head != nullptr) {
    tmp = head;
    head = tmp->next;
    delete tmp;
  }

  delete set;
  return OK;
}

ERR_STATUS DeleteUniv(univ_t* univ) {
  if (univ == nullptr)
    return ERROR;

  set_t* head = univ->head;
  set_t* tmp = nullptr;

  while (head != nullptr) {
    tmp = head;
    head = tmp->next;
    if (SetDeletePtr(tmp) == ERROR)
      return ERROR;
  }

  delete univ;
  return OK;
}

ERR_STATUS SetCreate(std::string setName, univ_t* univ) {
  if (univ == nullptr)
    return ERROR;

  set_t* set = InitSet(setName);
  if (set == nullptr)
    return ERROR;

  set_t* tmp = univ->head;

  if (univ->head == nullptr) {
    univ->head = set;
    return OK;
  }

  while (tmp->setName > set->setName) {
    if (tmp->next == nullptr)
      break;

    tmp = tmp->next;
  }

 // for (;tmp->setName > set->setName && tmp->next != nullptr; prev = tmp, tmp = tmp->next);
  
  if (tmp->next == nullptr && tmp->setName > set->setName) {
    tmp->next = set;
    set->prev = tmp;
    return OK;
  }

  if (tmp->setName == set->setName) {
    delete set;
    return ERROR_SAME_NAME;
  }

  set->next = tmp;
  if (univ->head == tmp)
    univ->head = set;
  else {
    tmp->prev->next = set;
    set->prev = tmp->prev;
  }
  tmp->prev = set;

  return OK;
}

ERR_STATUS PrintSetList(univ_t* univ) {
  if (univ == nullptr)
    return ERROR;

  if (univ->head == nullptr) {
    std::cout << "Empty..." << std::endl;
    return OK;
  }

  for (set_t* tmp = univ->head; tmp != nullptr; tmp = tmp->next) {
    std::cout << tmp->setName << ", ";
  }
  std::cout << std::endl;

  return OK;
}

set_t* SetSearch(std::string setName, univ_t* univ) {
  set_t* tmp = univ->head;

  while (tmp != nullptr) {
    if (tmp->setName == setName)
      return tmp;

    tmp = tmp->next;
  }

  return nullptr;
}

ERR_STATUS SetPrint(std::string setName, univ_t* univ) {
  if (univ == nullptr)
    return ERROR;

  set_t* set = SetSearch(setName, univ);
  if (set == nullptr) {
    std::cout << "ERROR: the set with this name does not exist" << std::endl;
    return OK;
  }

  if(set->head == nullptr) {
    std::cout << "Empty..." << std::endl;
    return OK;
  }

  for(elem_t* tmp = set->head; tmp != nullptr; tmp = tmp->next)
    std::cout << tmp->elemName << ", ";
  std::cout << std::endl;

  return OK;
}

ERR_STATUS SetDelete(std::string setName, univ_t* univ) {
  if (univ == nullptr)
    return ERROR;

  set_t* set = SetSearch(setName, univ);
  if (set == nullptr)
    return NOT_FOUND_SET;
  
  if (set->next == nullptr)
    if (set->prev == nullptr)
      univ->head = nullptr;
    else
      set->prev->next = nullptr;
  else
    if (set->prev == nullptr) {
      univ->head = set->next;
      set->next->prev = nullptr;
    }
    else {
      set->prev->next = set->next;
      set->next->prev = set->prev;
    }

  if (SetDeletePtr(set) == OK)
    return OK;

  return ERROR;
}

ERR_STATUS SetCardinality(std::string setName, univ_t* univ, int* card) {
  if (univ == nullptr)
    return ERROR;

  set_t* set = SetSearch(setName, univ);
  int count = 0;

  if (set == nullptr)
    return NOT_FOUND_SET;

  if (set->head == nullptr) {
    (*card) = 0;
    return OK;
  }

  for (elem_t* tmp = set->head; tmp != nullptr; tmp = tmp->next, ++count);
  (*card) = count;
  return OK;
}

ERR_STATUS ElemAdd(std::string elemName, std::string setName, univ_t* univ) {
  if (univ == nullptr)
    return ERROR;

  set_t* set = SetSearch(setName, univ);
  if (set == nullptr)
    return NOT_FOUND_SET;

  elem_t* elem = InitElem(elemName);
  if (elem == nullptr)
    return ERROR;

  elem_t* tmp = set->head;

  if (tmp == nullptr) {
    set->head = elem;
    return OK;
  }

  while (tmp->next) {
    if (!(tmp->elemName > elem->elemName))
      break;
    tmp = tmp->next;
  }

  if(tmp->next == nullptr && tmp->elemName > elem->elemName) {
    tmp->next = elem;
    elem->prev = tmp;
    return OK;
  }

  if(tmp->elemName == elem->elemName) {
    delete elem;
    return ERROR_SAME_NAME;
  }

  elem->next = tmp;
  if (set->head == tmp)
    set->head = elem;
  else {
    tmp->prev->next = elem;
    elem->prev = tmp->prev;
  }
  tmp->prev = elem;

  return OK;
}

elem_t* ElemSearchPtr(std::string elemName, set_t* set) {
  elem_t* tmp = set->head;

  while (tmp != nullptr) {
    if (tmp->elemName == elemName)
      return tmp;

    tmp = tmp->next;
  }

  return nullptr;
}


ERR_STATUS ElemSearch(std::string elemName, std::string setName, univ_t* univ) {
  if (univ == nullptr)
    return ERROR;

  set_t* set = SetSearch(setName, univ);
  if (set == nullptr)
    return NOT_FOUND_SET;

  elem_t* elem = ElemSearchPtr(elemName, set);
  if (elem == nullptr)
    return NOT_FOUND_EL;

  return OK;
}


ERR_STATUS ElemDelete(std::string elemName, std::string setName, univ_t* univ) {
  if (univ == nullptr)
    return ERROR;

  set_t* set = SetSearch(setName, univ);
  if (set == nullptr)
    return NOT_FOUND_SET;

  elem_t* elem = ElemSearchPtr(elemName, set);
  if (elem == nullptr)
    return NOT_FOUND_EL;

  if (elem->next == nullptr)
    if (elem->prev == nullptr)
      set->head = nullptr;
    else
      elem->prev->next = nullptr;
  else
    if (elem->prev == nullptr) {
      set->head = elem->next;
      elem->next->prev = nullptr;
    }
    else {
      elem->prev->next = elem->next;
      elem->next->prev = elem->prev;
    }

  delete elem;
  return OK;
}
