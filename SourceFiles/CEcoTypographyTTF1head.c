/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1head
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoTypographyTTF1head
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

/* Подключаемые заголовки файлов */
#include "CEcoTypographyTTF1head.h"
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoTypographyTTF1head
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1head_QueryInterface(/* in */ struct IEcoTypographyTTF1head* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoTypographyTTF1head* pCMe = (CEcoTypographyTTF1head*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoTypographyTTF1head) ) {
        *ppv = &pCMe->m_pVTblIhead;
        pCMe->m_pVTblIhead->AddRef((IEcoTypographyTTF1head*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIhead;
        pCMe->m_pVTblIhead->AddRef((IEcoTypographyTTF1head*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoTypographyTTF1head
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1head_AddRef(/* in */ struct IEcoTypographyTTF1head* me) {
    CEcoTypographyTTF1head* pCMe = (CEcoTypographyTTF1head*)me;

    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoTypographyTTF1head
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1head_Release(/* in */ struct IEcoTypographyTTF1head* me) {
    CEcoTypographyTTF1head* pCMe = (CEcoTypographyTTF1head*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoTypographyTTF1head((IEcoTypographyTTF1head*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция get_Descriptor
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR* CEcoTypographyTTF1head_get_Descriptor(/* in */ struct IEcoTypographyTTF1head* me) {
    CEcoTypographyTTF1head* pCMe = (CEcoTypographyTTF1head*)me;

    if (me == 0 ) {
        return 0;
    }

    return &pCMe->m_Descriptor;
}

/*
 *
 * <сводка>
 *   Функция set_Descriptor
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoTypographyTTF1head_set_Descriptor(/* in */ struct IEcoTypographyTTF1head* me, /* in */ ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR* descriptor) {
    CEcoTypographyTTF1head* pCMe = (CEcoTypographyTTF1head*)me;
    uint8_t index = 0;
    byte_t* ptrSrc = 0;
    byte_t* ptrDst = 0;

    if (me == 0 || descriptor == 0) {
        return;
    }

    ptrSrc = (byte_t*)&pCMe->m_Descriptor;
    ptrDst = (byte_t*)descriptor;

    for (index = 0; index< sizeof(ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR); index++) {
        ptrSrc[index] = ptrDst[index];
    }
}

/* Create Virtual Table */
IEcoTypographyTTF1headVTbl g_xD0C5EC3F03A54EE49588978F2731E9E4VTbl = {
    CEcoTypographyTTF1head_QueryInterface,
    CEcoTypographyTTF1head_AddRef,
    CEcoTypographyTTF1head_Release,
    CEcoTypographyTTF1head_get_Descriptor,
    CEcoTypographyTTF1head_set_Descriptor

};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t createCEcoTypographyTTF1head(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1head** ppIMember) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoTypographyTTF1head* pCMe = 0;

    /* Проверка указателей */
    if (ppIMember == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoTypographyTTF1head*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoTypographyTTF1head));

    /* Сохранение указателя на системный интерфейс */
    //pCMe->m_pISys = pISystem;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoTypographyTTF1head */
    pCMe->m_pVTblIhead = &g_xD0C5EC3F03A54EE49588978F2731E9E4VTbl;

    /* Возврат указателя на интерфейс */
    *ppIMember = (IEcoTypographyTTF1head*)pCMe;

    /* Освобождение системного интерфейса */
    pISys->pVTbl->Release(pISys);
    pIBus->pVTbl->Release(pIBus);

    return 0;
};

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void deleteCEcoTypographyTTF1head(/* in */ IEcoTypographyTTF1head* pIMember) {
    CEcoTypographyTTF1head* pCMe = (CEcoTypographyTTF1head*)pIMember;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIMember != 0 ) {

        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
};
