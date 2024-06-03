/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1loca
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoTypographyTTF1loca
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

/* Подключаемые заголовки файлов */
#include "CEcoTypographyTTF1loca.h"
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoTypographyTTF1loca
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1loca_QueryInterface(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoTypographyTTF1loca) ) {
        *ppv = &pCMe->m_pVTblIloca;
        pCMe->m_pVTblIloca->AddRef((IEcoTypographyTTF1loca*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIloca;
        pCMe->m_pVTblIloca->AddRef((IEcoTypographyTTF1loca*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoTypographyTTF1loca
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1loca_AddRef(/* in */ struct IEcoTypographyTTF1loca* me) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

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
 *   Функция Release для интерфейса IEcoTypographyTTF1loca
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1loca_Release(/* in */ struct IEcoTypographyTTF1loca* me) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoTypographyTTF1loca((IEcoTypographyTTF1loca*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция get_OffsetFormat
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1loca_get_OffsetFormat(/* in */ struct IEcoTypographyTTF1loca* me) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_OffsetFormat;
}

/*
 *
 * <сводка>
 *   Функция set_OffsettFormat
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1loca_set_OffsettFormat(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ int16_t version) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 ) {
        return 0;
    }

    if (version == ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET16 || version == ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET32) {
        pCMe->m_OffsetFormat = version;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция get_Offset16
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint16_t CEcoTypographyTTF1loca_get_Offset16(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ uint16_t n) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 ) {
        return 0;
    }

    if (pCMe->m_OffsetFormat == ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET16 && pCMe->m_TableLength > (uint32_t)(n*4)) {
        return (uint16_t)(pCMe->m_TableData[n*4+2] << 8) | (uint16_t)(pCMe->m_TableData[n*4+3]);
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция set_Offset16
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1loca_set_Offset16(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ uint16_t n, /* in */ uint16_t offset) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_OffsetFormat == ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET16 && pCMe->m_TableLength > (uint32_t)n*2) {
        ((uint16_t*)pCMe->m_TableData)[n*2] = offset;
        result = 0;
    }

    return result;
}

/*
 *
 * <сводка>
 *   Функция get_Offset32
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1loca_get_Offset32(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ uint16_t n) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 ) {
        return 0;
    }

    if (pCMe->m_TableLength > (uint32_t)n*4) {
        return (uint32_t)(pCMe->m_TableData[n*4] << 32) | (uint32_t)(pCMe->m_TableData[n*4+1] << 16) | (uint32_t)(pCMe->m_TableData[n*4+2] << 8) | (uint32_t)(pCMe->m_TableData[n*4+3]);
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция set_Offset32
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1loca_set_Offset32(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ uint16_t n, /* in */ uint32_t offset) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_OffsetFormat == ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET32 && pCMe->m_TableLength > (uint32_t)n*4) {
        ((uint32_t*)pCMe->m_TableData)[n*4] = offset;
        result = 0;
    }

    return result;
}

/*
 *
 * <сводка>
 *   Функция get_OffsetCount
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint16_t CEcoTypographyTTF1loca_get_OffsetCount(/* in */ struct IEcoTypographyTTF1loca* me) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;
    uint16_t iCount = 0;

    if (me == 0 ) {
        return 0;
    }

    if (pCMe->m_OffsetFormat == ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET16 && pCMe->m_TableLength > 0) {
        iCount = pCMe->m_TableLength / 2;
    }
    else if (pCMe->m_OffsetFormat == ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET32 && pCMe->m_TableLength > 0) {
        iCount = pCMe->m_TableLength / 4;
    }

    return iCount;
}

/*
 *
 * <сводка>
 *   Функция set_TableData
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoTypographyTTF1loca_set_TableData(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ byte_t* pData, /* in */ uint32_t length) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 ) {
        return;
    }

    if (pCMe-> m_TableData != 0 && pCMe->m_TableLength > 0) {
        pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pCMe-> m_TableData);
        pCMe-> m_TableData = 0;
        pCMe->m_TableLength = 0;
    }

    if (length > 0) {
        pCMe-> m_TableData = (byte_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, length);
        pCMe->m_TableLength = length;
    }

    if (pData != 0) {
        pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, pCMe-> m_TableData , pData, length);
    }
}

/*
 *
 * <сводка>
 *   Функция get_TableData
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
byte_t* CEcoTypographyTTF1loca_get_TableData(/* in */ struct IEcoTypographyTTF1loca* me) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_TableData;
}

/*
 *
 * <сводка>
 *   Функция get_TableLength
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1loca_get_TableLength(/* in */ struct IEcoTypographyTTF1loca* me) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_TableLength;
}

/* Create Virtual Table */
IEcoTypographyTTF1locaVTbl g_x5838C7AA9E63406ABD6B35B9C8DA4F79VTbl = {
    CEcoTypographyTTF1loca_QueryInterface,
    CEcoTypographyTTF1loca_AddRef,
    CEcoTypographyTTF1loca_Release,
    CEcoTypographyTTF1loca_get_OffsetFormat,
    CEcoTypographyTTF1loca_set_OffsettFormat,
    CEcoTypographyTTF1loca_get_Offset16,
    CEcoTypographyTTF1loca_set_Offset16,
    CEcoTypographyTTF1loca_get_Offset32,
    CEcoTypographyTTF1loca_set_Offset32,
    CEcoTypographyTTF1loca_get_OffsetCount,
    CEcoTypographyTTF1loca_set_TableData,
    CEcoTypographyTTF1loca_get_TableData,
    CEcoTypographyTTF1loca_get_TableLength

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
int16_t createCEcoTypographyTTF1loca(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1loca** ppIMember) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoTypographyTTF1loca* pCMe = 0;

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
    pCMe = (CEcoTypographyTTF1loca*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoTypographyTTF1loca));

    /* Сохранение указателя на системный интерфейс */
    //pCMe->m_pISys = pISystem;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoTypographyTTF1loca */
    pCMe->m_pVTblIloca = &g_x5838C7AA9E63406ABD6B35B9C8DA4F79VTbl;

    pCMe-> m_OffsetFormat = 0;
    pCMe-> m_TableData = 0;
    pCMe->m_TableLength = 0;

    /* Возврат указателя на интерфейс */
    *ppIMember = (IEcoTypographyTTF1loca*)pCMe;

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
void deleteCEcoTypographyTTF1loca(/* in */ IEcoTypographyTTF1loca* pIMember) {
    CEcoTypographyTTF1loca* pCMe = (CEcoTypographyTTF1loca*)pIMember;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIMember != 0 ) {

        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe-> m_TableData != 0 && pCMe->m_TableLength > 0) {
            pIMem->pVTbl->Free(pIMem, pCMe-> m_TableData);
            pCMe-> m_TableData = 0;
            pCMe->m_TableLength = 0;
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
};
