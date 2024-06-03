/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1TableRecord
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoTypographyTTF1TableRecord
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

/* Подключаемые заголовки файлов */
#include "CEcoTypographyTTF1TableRecord.h"
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoTypographyTTF1TableRecord
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1TableRecord_QueryInterface(/* in */ struct IEcoTypographyTTF1TableRecord* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoTypographyTTF1TableRecord* pCMe = (CEcoTypographyTTF1TableRecord*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoTypographyTTF1TableRecord) ) {
        *ppv = &pCMe->m_pVTblITableRecord;
        pCMe->m_pVTblITableRecord->AddRef((IEcoTypographyTTF1TableRecord*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblITableRecord;
        pCMe->m_pVTblITableRecord->AddRef((IEcoTypographyTTF1TableRecord*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoTypographyTTF1TableRecord
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1TableRecord_AddRef(/* in */ struct IEcoTypographyTTF1TableRecord* me) {
    CEcoTypographyTTF1TableRecord* pCMe = (CEcoTypographyTTF1TableRecord*)me;

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
 *   Функция Release для интерфейса IEcoTypographyTTF1TableRecord
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1TableRecord_Release(/* in */ struct IEcoTypographyTTF1TableRecord* me) {
    CEcoTypographyTTF1TableRecord* pCMe = (CEcoTypographyTTF1TableRecord*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoTypographyTTF1TableRecord((IEcoTypographyTTF1TableRecord*)pCMe);
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
ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR* CEcoTypographyTTF1TableRecord_get_Descriptor(/* in */ struct IEcoTypographyTTF1TableRecord* me) {
    CEcoTypographyTTF1TableRecord* pCMe = (CEcoTypographyTTF1TableRecord*)me;

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
void CEcoTypographyTTF1TableRecord_set_Descriptor(/* in */ struct IEcoTypographyTTF1TableRecord* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR* descriptor) {
    CEcoTypographyTTF1TableRecord* pCMe = (CEcoTypographyTTF1TableRecord*)me;
    uint8_t index = 0;
    byte_t* ptrSrc = 0;
    byte_t* ptrDst = 0;

    if (me == 0 || descriptor == 0) {
        return;
    }

    ptrSrc = (byte_t*)&pCMe->m_Descriptor;
    ptrDst = (byte_t*)descriptor;

    for (index = 0; index< sizeof(ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR); index++) {
        ptrSrc[index] = ptrDst[index];
    }
}

/*
 *
 * <сводка>
 *   Функция get_Table
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoUnknown* CEcoTypographyTTF1TableRecord_get_Table(/* in */ struct IEcoTypographyTTF1TableRecord* me) {
    CEcoTypographyTTF1TableRecord* pCMe = (CEcoTypographyTTF1TableRecord*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Table;
}

/*
 *
 * <сводка>
 *   Функция set_Table
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoTypographyTTF1TableRecord_set_Table(/* in */ struct IEcoTypographyTTF1TableRecord* me, /* in */ IEcoUnknown* pITable) {
    CEcoTypographyTTF1TableRecord* pCMe = (CEcoTypographyTTF1TableRecord*)me;

    if (me == 0 || pITable == 0) {
        return;
    }
    if (pCMe->m_Table != 0) {
        pCMe->m_Table->pVTbl->Release(pCMe->m_Table);
    }
    pCMe->m_Table = pITable;
    pCMe->m_Table->pVTbl->AddRef(pCMe->m_Table);
}


/* Create Virtual Table */
IEcoTypographyTTF1TableRecordVTbl g_x2F03C0F83E874D1388AD5EB4A91CCA6EVTbl = {
    CEcoTypographyTTF1TableRecord_QueryInterface,
    CEcoTypographyTTF1TableRecord_AddRef,
    CEcoTypographyTTF1TableRecord_Release,
    CEcoTypographyTTF1TableRecord_get_Descriptor,
    CEcoTypographyTTF1TableRecord_set_Descriptor,
    CEcoTypographyTTF1TableRecord_get_Table,
    CEcoTypographyTTF1TableRecord_set_Table

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
int16_t createCEcoTypographyTTF1TableRecord(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1TableRecord** ppIMember) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoTypographyTTF1TableRecord* pCMe = 0;

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
    pCMe = (CEcoTypographyTTF1TableRecord*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoTypographyTTF1TableRecord));

    /* Сохранение указателя на системный интерфейс */
    //pCMe->m_pISys = pISystem;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoTypographyTTF1TableRecord */
    pCMe->m_pVTblITableRecord = &g_x2F03C0F83E874D1388AD5EB4A91CCA6EVTbl;

    pCMe->m_Table = 0;

    /* Создание экземпляра для работы со строкой */
    pCMe->m_pIString = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        return result;
    }

    /* Возврат указателя на интерфейс */
    *ppIMember = (IEcoTypographyTTF1TableRecord*)pCMe;

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
void deleteCEcoTypographyTTF1TableRecord(/* in */ IEcoTypographyTTF1TableRecord* pIMember) {
    CEcoTypographyTTF1TableRecord* pCMe = (CEcoTypographyTTF1TableRecord*)pIMember;
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
