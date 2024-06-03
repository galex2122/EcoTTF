/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1gasp
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoTypographyTTF1gasp
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

/* Подключаемые заголовки файлов */
#include "CEcoTypographyTTF1gasp.h"
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoTypographyTTF1gasp
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1gasp_QueryInterface(/* in */ struct IEcoTypographyTTF1gasp* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoTypographyTTF1gasp* pCMe = (CEcoTypographyTTF1gasp*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoTypographyTTF1gasp) ) {
        *ppv = &pCMe->m_pVTblIgasp;
        pCMe->m_pVTblIgasp->AddRef((IEcoTypographyTTF1gasp*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIgasp;
        pCMe->m_pVTblIgasp->AddRef((IEcoTypographyTTF1gasp*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoTypographyTTF1gasp
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1gasp_AddRef(/* in */ struct IEcoTypographyTTF1gasp* me) {
    CEcoTypographyTTF1gasp* pCMe = (CEcoTypographyTTF1gasp*)me;

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
 *   Функция Release для интерфейса IEcoTypographyTTF1gasp
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1gasp_Release(/* in */ struct IEcoTypographyTTF1gasp* me) {
    CEcoTypographyTTF1gasp* pCMe = (CEcoTypographyTTF1gasp*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoTypographyTTF1gasp((IEcoTypographyTTF1gasp*)pCMe);
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
ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* CEcoTypographyTTF1gasp_get_Descriptor(/* in */ struct IEcoTypographyTTF1gasp* me) {
    CEcoTypographyTTF1gasp* pCMe = (CEcoTypographyTTF1gasp*)me;

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
void CEcoTypographyTTF1gasp_set_Descriptor(/* in */ struct IEcoTypographyTTF1gasp* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor) {
    CEcoTypographyTTF1gasp* pCMe = (CEcoTypographyTTF1gasp*)me;
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
IEcoList1* CEcoTypographyTTF1gasp_get_TableDirectory(/* in */ struct IEcoTypographyTTF1gasp* me) {
    CEcoTypographyTTF1gasp* pCMe = (CEcoTypographyTTF1gasp*)me;

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
void CEcoTypographyTTF1gasp_set_TableDirectory(/* in */ struct IEcoTypographyTTF1gasp* me, /* in */ IEcoList1* pIRecords) {
    CEcoTypographyTTF1gasp* pCMe = (CEcoTypographyTTF1gasp*)me;

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
IEcoTypographyTTF1gaspVTbl g_x0EA04735D9884930AD389042557E93EBVTbl = {
    CEcoTypographyTTF1gasp_QueryInterface,
    CEcoTypographyTTF1gasp_AddRef,
    CEcoTypographyTTF1gasp_Release,
    CEcoTypographyTTF1gasp_get_Descriptor,
    CEcoTypographyTTF1gasp_set_Descriptor,
    CEcoTypographyTTF1gasp_get_TableDirectory,
    CEcoTypographyTTF1gasp_set_TableDirectory

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
int16_t createCEcoTypographyTTF1gasp(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1gasp** ppIMember) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoTypographyTTF1gasp* pCMe = 0;

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
    pCMe = (CEcoTypographyTTF1gasp*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoTypographyTTF1gasp));

    /* Сохранение указателя на системный интерфейс */
    //pCMe->m_pISys = pISystem;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoTypographyTTF1gasp */
    pCMe->m_pVTblIgasp = &g_x0EA04735D9884930AD389042557E93EBVTbl;

    pCMe->m_TableDirectory = 0;

    /* Создание экземпляра для работы со строкой */
    pCMe->m_pIString = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        return result;
    }

    /* Возврат указателя на интерфейс */
    *ppIMember = (IEcoTypographyTTF1gasp*)pCMe;

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
void deleteCEcoTypographyTTF1gasp(/* in */ IEcoTypographyTTF1gasp* pIMember) {
    CEcoTypographyTTF1gasp* pCMe = (CEcoTypographyTTF1gasp*)pIMember;
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
