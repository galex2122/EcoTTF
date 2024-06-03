/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1VDMX
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoTypographyTTF1VDMX
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

/* Подключаемые заголовки файлов */
#include "CEcoTypographyTTF1VDMX.h"
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoTypographyTTF1VDMX
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1VDMX_QueryInterface(/* in */ struct IEcoTypographyTTF1VDMX* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoTypographyTTF1VDMX* pCMe = (CEcoTypographyTTF1VDMX*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoTypographyTTF1VDMX) ) {
        *ppv = &pCMe->m_pVTblIVDMX;
        pCMe->m_pVTblIVDMX->AddRef((IEcoTypographyTTF1VDMX*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIVDMX;
        pCMe->m_pVTblIVDMX->AddRef((IEcoTypographyTTF1VDMX*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoTypographyTTF1VDMX
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1VDMX_AddRef(/* in */ struct IEcoTypographyTTF1VDMX* me) {
    CEcoTypographyTTF1VDMX* pCMe = (CEcoTypographyTTF1VDMX*)me;

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
 *   Функция Release для интерфейса IEcoTypographyTTF1VDMX
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1VDMX_Release(/* in */ struct IEcoTypographyTTF1VDMX* me) {
    CEcoTypographyTTF1VDMX* pCMe = (CEcoTypographyTTF1VDMX*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoTypographyTTF1VDMX((IEcoTypographyTTF1VDMX*)pCMe);
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
ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* CEcoTypographyTTF1VDMX_get_Descriptor(/* in */ struct IEcoTypographyTTF1VDMX* me) {
    CEcoTypographyTTF1VDMX* pCMe = (CEcoTypographyTTF1VDMX*)me;

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
void CEcoTypographyTTF1VDMX_set_Descriptor(/* in */ struct IEcoTypographyTTF1VDMX* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor) {
    CEcoTypographyTTF1VDMX* pCMe = (CEcoTypographyTTF1VDMX*)me;
    uint8_t index = 0;
    byte_t* ptrSrc = 0;
    byte_t* ptrDst = 0;

    if (me == 0 || descriptor == 0) {
        return;
    }

    ptrSrc = (byte_t*)&pCMe->m_Descriptor;
    ptrDst = (byte_t*)descriptor;

    for (index = 0; index< sizeof(ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR); index++) {
        ptrSrc[index] = ptrDst[index];
    }
}

/*
 *
 * <сводка>
 *   Функция get_TableDirectory
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoList1* CEcoTypographyTTF1VDMX_get_TableDirectory(/* in */ struct IEcoTypographyTTF1VDMX* me) {
    CEcoTypographyTTF1VDMX* pCMe = (CEcoTypographyTTF1VDMX*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_TableDirectory;
}

/*
 *
 * <сводка>
 *   Функция set_TableDirectory
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoTypographyTTF1VDMX_set_TableDirectory(/* in */ struct IEcoTypographyTTF1VDMX* me, /* in */ IEcoList1* pIRecords) {
    CEcoTypographyTTF1VDMX* pCMe = (CEcoTypographyTTF1VDMX*)me;

    if (me == 0 || pIRecords == 0) {
        return;
    }
    if (pCMe->m_TableDirectory != 0) {
        pCMe->m_TableDirectory->pVTbl->Release(pCMe->m_TableDirectory);
    }
    pCMe->m_TableDirectory = pIRecords;
    pCMe->m_TableDirectory->pVTbl->AddRef(pCMe->m_TableDirectory);
}


/* Create Virtual Table */
IEcoTypographyTTF1VDMXVTbl g_x023DC9551DD947A9884DBC3166BF0A29VTbl = {
    CEcoTypographyTTF1VDMX_QueryInterface,
    CEcoTypographyTTF1VDMX_AddRef,
    CEcoTypographyTTF1VDMX_Release,
    CEcoTypographyTTF1VDMX_get_Descriptor,
    CEcoTypographyTTF1VDMX_set_Descriptor,
    CEcoTypographyTTF1VDMX_get_TableDirectory,
    CEcoTypographyTTF1VDMX_set_TableDirectory

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
int16_t createCEcoTypographyTTF1VDMX(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1VDMX** ppIMember) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoTypographyTTF1VDMX* pCMe = 0;

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
    pCMe = (CEcoTypographyTTF1VDMX*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoTypographyTTF1VDMX));

    /* Сохранение указателя на системный интерфейс */
    //pCMe->m_pISys = pISystem;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoTypographyTTF1VDMX */
    pCMe->m_pVTblIVDMX = &g_x023DC9551DD947A9884DBC3166BF0A29VTbl;

    pCMe->m_TableDirectory = 0;

    /* Создание экземпляра для работы со строкой */
    pCMe->m_pIString = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        return result;
    }

    /* Возврат указателя на интерфейс */
    *ppIMember = (IEcoTypographyTTF1VDMX*)pCMe;

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
void deleteCEcoTypographyTTF1VDMX(/* in */ IEcoTypographyTTF1VDMX* pIMember) {
    CEcoTypographyTTF1VDMX* pCMe = (CEcoTypographyTTF1VDMX*)pIMember;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIMember != 0 ) {

        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe->m_pIString != 0) {
            pCMe->m_pIString->pVTbl->Release(pCMe->m_pIString);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
};
