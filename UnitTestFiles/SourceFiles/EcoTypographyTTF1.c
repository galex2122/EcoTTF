/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoTypographyTTF1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"
#include "IdEcoDateTime1.h"
#include "IdEcoLog1.h"
#include "IEcoLog1FileAffiliate.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoTypographyTTF1.h"

#include "EcoFormDialog.h"

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на интерфейс работы с журналом */
    IEcoLog1* pILog = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    /* Указатель на интерфейс работы со строкой */
    IEcoString1* pIStr = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoTypographyTTF1* pITTF = 0;
    IEcoTypographyTTF1FontFile* pIFontFile = 0;
    IEcoTypographyTTF1TableRecord* pITableRecord = 0;
    IEcoList1* pITableDirectory = 0;
    IEcoTypographyTTF1head* pIhead = 0;
    IEcoTypographyTTF1cmap* pIcmap = 0;
    IEcoTypographyTTF1glyf* pIglyf = 0;
    IEcoTypographyTTF1maxp* pImaxp = 0;
    uint32_t index = 0;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoTypographyTTF1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_F9CC67B493F648599E408FB600656E51);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с журналом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLog1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_97322B6765B74342BBCE38798A0B40B5);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со строкой */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoString1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_84CC0A7DBABD44EEBE749C9A8312D37E);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoList1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_53884AFC93C448ECAA929C8D3A562281);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с датой и вреенем */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoDateTime1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5B2BA17BEA704527BC708F88568FE115);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

   /* Получение интерфейса  для работы со строкой */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void**) &pIStr);
    if (result != 0 || pIStr == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса  для работы с журналом */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**) &pILog);
    if (result != 0 || pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**) &pIFileAffiliate);
    if (result != 0 || pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    pILog->pVTbl->AddAffiliate(pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    pILog->pVTbl->Info(pILog, "Start tests!!!");


    /* Получение тестируемого интерфейса */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoTypographyTTF1, 0, &IID_IEcoTypographyTTF1, (void**) &pITTF);
    if (result != 0 && pITTF == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    pIFontFile = pITTF->pVTbl->Load(pITTF, "C:\\Users\\Alexey\\Desktop\\EcoCGI\\Eco.Typography.TTF1\\UnitTestFiles\\timesbd.ttf");

    pILog->pVTbl->Info(pILog, "--------------------*   Table Directory  *--------------------");
    pILog->pVTbl->InfoFormat(pILog, "sfntVersion    = %4X", pIFontFile->pVTbl->get_Descriptor(pIFontFile)->sfntVersion);
    pILog->pVTbl->InfoFormat(pILog, "numTables      = %2X (%d)", byteswap_uint16_t(pIFontFile->pVTbl->get_Descriptor(pIFontFile)->numTables), byteswap_uint16_t(pIFontFile->pVTbl->get_Descriptor(pIFontFile)->numTables));
    pILog->pVTbl->InfoFormat(pILog, "searchRange    = %2X (%d)", byteswap_uint16_t(pIFontFile->pVTbl->get_Descriptor(pIFontFile)->searchRange), byteswap_uint16_t(pIFontFile->pVTbl->get_Descriptor(pIFontFile)->searchRange));
    pILog->pVTbl->InfoFormat(pILog, "entrySelector  = %2X (%d)", byteswap_uint16_t(pIFontFile->pVTbl->get_Descriptor(pIFontFile)->entrySelector), byteswap_uint16_t(pIFontFile->pVTbl->get_Descriptor(pIFontFile)->entrySelector));
    pILog->pVTbl->InfoFormat(pILog, "rangeShift     = %2X (%d)", byteswap_uint16_t(pIFontFile->pVTbl->get_Descriptor(pIFontFile)->rangeShift), byteswap_uint16_t(pIFontFile->pVTbl->get_Descriptor(pIFontFile)->rangeShift));

    pITableDirectory = pIFontFile->pVTbl->get_TableDirectory(pIFontFile);
    for (index = 0; index < pITableDirectory->pVTbl->Count(pITableDirectory); index++) {
        pITableRecord = (IEcoTypographyTTF1TableRecord*)pITableDirectory->pVTbl->Item(pITableDirectory, index);
        pILog->pVTbl->InfoFormat(pILog, "-----------------*   Table Record [%d]  *------------------", index);
        pILog->pVTbl->InfoFormat(pILog, "tag            = %4X - %c%c%c%c", pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag, ((uint8_t*)&pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag)[0], ((uint8_t*)&pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag)[1], ((uint8_t*)&pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag)[2], ((uint8_t*)&pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag)[3]);
        pILog->pVTbl->InfoFormat(pILog, "checksum       = %4X (%d)", byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->checksum), byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->checksum));
        pILog->pVTbl->InfoFormat(pILog, "offset         = %4X (%d)", byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->offset), byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->offset));
        pILog->pVTbl->InfoFormat(pILog, "length         = %4X (%d)", byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->length), byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->length));
        pILog->pVTbl->InfoFormat(pILog, "-----------------------------------------------------------", index);

        if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x64616568) {
            pIhead = (IEcoTypographyTTF1head*)pITableRecord->pVTbl->get_Table(pITableRecord);
            pILog->pVTbl->InfoFormat(pILog, "majorVersion           = %2X (%d)", byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->majorVersion), byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->majorVersion));
            pILog->pVTbl->InfoFormat(pILog, "minorVersion           = %2X (%d)", byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->minorVersion), byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->minorVersion));
            pILog->pVTbl->InfoFormat(pILog, "fontRevision           = %4X (%d)", byteswap_uint32_t(pIhead->pVTbl->get_Descriptor(pIhead)->fontRevision), byteswap_uint32_t(pIhead->pVTbl->get_Descriptor(pIhead)->fontRevision));
            pILog->pVTbl->InfoFormat(pILog, "checksumAdjustment     = %4X (%d)", byteswap_uint32_t(pIhead->pVTbl->get_Descriptor(pIhead)->checksumAdjustment), byteswap_uint32_t(pIhead->pVTbl->get_Descriptor(pIhead)->checksumAdjustment));
            pILog->pVTbl->InfoFormat(pILog, "magicNumber            = %4X (%d)", byteswap_uint32_t(pIhead->pVTbl->get_Descriptor(pIhead)->magicNumber), byteswap_uint32_t(pIhead->pVTbl->get_Descriptor(pIhead)->magicNumber));
            pILog->pVTbl->InfoFormat(pILog, "flags                  = %2X (%d)", byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->flags), byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->flags));
            pILog->pVTbl->InfoFormat(pILog, "unitsPerEm             = %2X (%d)", byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->unitsPerEm), byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->unitsPerEm));
            pILog->pVTbl->InfoFormat(pILog, "created                = %8X (%d)", byteswap_int64_t(pIhead->pVTbl->get_Descriptor(pIhead)->created), byteswap_int64_t(pIhead->pVTbl->get_Descriptor(pIhead)->created));
            pILog->pVTbl->InfoFormat(pILog, "modified               = %8X (%d)", byteswap_int64_t(pIhead->pVTbl->get_Descriptor(pIhead)->modified), byteswap_int64_t(pIhead->pVTbl->get_Descriptor(pIhead)->modified));
            pILog->pVTbl->InfoFormat(pILog, "xMin                   = %2X (%d)", byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->xMin), byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->xMin));
            pILog->pVTbl->InfoFormat(pILog, "yMin                   = %2X (%d)", byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->yMin), byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->yMin));
            pILog->pVTbl->InfoFormat(pILog, "xMax                   = %2X (%d)", byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->xMax), byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->xMax));
            pILog->pVTbl->InfoFormat(pILog, "yMax                   = %2X (%d)", byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->yMax), byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->yMax));
            pILog->pVTbl->InfoFormat(pILog, "macStyle               = %2X (%d)", byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->macStyle), byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->macStyle));
            pILog->pVTbl->InfoFormat(pILog, "lowestRecPPEM          = %2X (%d)", byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->lowestRecPPEM), byteswap_uint16_t(pIhead->pVTbl->get_Descriptor(pIhead)->lowestRecPPEM));
            pILog->pVTbl->InfoFormat(pILog, "fontDirectionHint      = %2X (%d)", byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->fontDirectionHint), byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->fontDirectionHint));
            pILog->pVTbl->InfoFormat(pILog, "indexToLocFormat       = %2X (%d)", byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->indexToLocFormat), byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->indexToLocFormat));
            pILog->pVTbl->InfoFormat(pILog, "glyphDataFormat        = %2X (%d)", byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->glyphDataFormat), byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->glyphDataFormat));
        }

       // if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x70616D63) {
       //     pIcmap = (IEcoTypographyTTF1cmap*)pITableRecord->pVTbl->get_Table(pITableRecord);
       //     pILog->pVTbl->InfoFormat(pILog, "version         = %2X (%d)", byteswap_uint16_t(pIcmap->pVTbl->get_Descriptor(pIcmap)->version), byteswap_uint16_t(pIcmap->pVTbl->get_Descriptor(pIcmap)->version));
       //     pILog->pVTbl->InfoFormat(pILog, "numberSubtables = %2X (%d)", byteswap_uint16_t(pIcmap->pVTbl->get_Descriptor(pIcmap)->numberSubtables), byteswap_uint16_t(pIcmap->pVTbl->get_Descriptor(pIcmap)->numberSubtables));
       // }
        if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x7078616D) {
            pImaxp = (IEcoTypographyTTF1maxp*)pITableRecord->pVTbl->get_Table(pITableRecord);
            pILog->pVTbl->InfoFormat(pILog, "version         = %4X (%d)", byteswap_uint32_t(pImaxp->pVTbl->get_Descriptor(pImaxp)->version), byteswap_uint32_t(pImaxp->pVTbl->get_Descriptor(pImaxp)->version));
            pILog->pVTbl->InfoFormat(pILog, "numGlyphs       = %2X (%d)", byteswap_uint16_t(pImaxp->pVTbl->get_Descriptor(pImaxp)->numGlyphs), byteswap_uint16_t(pImaxp->pVTbl->get_Descriptor(pImaxp)->numGlyphs));
        }
    }

    /* Предросмотр шрифта  */
    DialogPreview(pIFontFile);
	//pITTF->pVTbl->Save(pITTF, pIFontFile, "C:\\Users\\Alexey\\Desktop\\EcoCGI\\Eco.Typography.TTF1\\UnitTestFiles\\timesbddescriptor.ttf");

    /* Освлбождение блока памяти */
Release:

    /* Освобождение интерфейса для работы с журналированием данных */
    if (pILog != 0) {
        pILog->pVTbl->Release(pILog);
    }

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение интерфейса работы со строкой */
    if (pIStr != 0) {
        pIStr->pVTbl->Release(pIStr);
    }

    /* Освобождение тестируемого интерфейса */
    if (pITTF != 0) {
        pITTF->pVTbl->Release(pITTF);
    }

    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

