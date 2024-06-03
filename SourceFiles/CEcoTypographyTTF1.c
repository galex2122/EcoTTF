/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoTypographyTTF1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IdEcoList1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoTypographyTTF1.h"
#include "CEcoTypographyTTF1FontFile.h"
#include "CEcoTypographyTTF1TableRecord.h"
#include "CEcoTypographyTTF1head.h"
#include "CEcoTypographyTTF1cmap.h"
#include "CEcoTypographyTTF1glyf.h"
#include "CEcoTypographyTTF1maxp.h"
#include "CEcoTypographyTTF1loca.h"

#define CHECK_BIT(var,pos) (((var)>>(pos)) & 1)

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoTypographyTTF1
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1_QueryInterface(/* in */ struct IEcoTypographyTTF1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoTypographyTTF1) ) {
        *ppv = &pCMe->m_pVTblIEcoTypographyTTF1;
        pCMe->m_pVTblIEcoTypographyTTF1->AddRef((IEcoTypographyTTF1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoTypographyTTF1;
        pCMe->m_pVTblIEcoTypographyTTF1->AddRef((IEcoTypographyTTF1*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoTypographyTTF1
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1_AddRef(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;

    /* Проверка указателя */
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
 *   Функция Release для интерфейса IEcoTypographyTTF1
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1_Release(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoTypographyTTF1((IEcoTypographyTTF1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция createFontFile
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoTypographyTTF1FontFile* CEcoTypographyTTF1_createFontFile(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    IEcoTypographyTTF1FontFile* pIFontFile = 0;
    uint16_t result = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    result = createCEcoTypographyTTF1FontFile((IEcoUnknown*)pCMe->m_pISys, 0, (IEcoTypographyTTF1FontFile**)&pIFontFile);

    return pIFontFile;
}

/*
 *
 * <сводка>
 *   Функция createTableRecord
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoTypographyTTF1TableRecord* CEcoTypographyTTF1_createTableRecord(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    IEcoTypographyTTF1TableRecord* pITableRecord = 0;
    uint16_t result = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    result = createCEcoTypographyTTF1TableRecord((IEcoUnknown*)pCMe->m_pISys, 0, (IEcoTypographyTTF1TableRecord**)&pITableRecord);

    return pITableRecord;
}

/*
 *
 * <сводка>
 *   Функция create_head
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoTypographyTTF1head* CEcoTypographyTTF1_create_head(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    IEcoTypographyTTF1head* pIhead = 0;
    uint16_t result = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    result = createCEcoTypographyTTF1head((IEcoUnknown*)pCMe->m_pISys, 0, (IEcoTypographyTTF1head**)&pIhead);

    return pIhead;
}

/*
 *
 * <сводка>
 *   Функция create_cmap
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoTypographyTTF1cmap* CEcoTypographyTTF1_create_cmap(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    IEcoTypographyTTF1cmap* pIcmap = 0;
    uint16_t result = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    result = createCEcoTypographyTTF1cmap((IEcoUnknown*)pCMe->m_pISys, 0, (IEcoTypographyTTF1cmap**)&pIcmap);

    return pIcmap;
}

/*
 *
 * <сводка>
 *   Функция create_glyf
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoTypographyTTF1glyf* CEcoTypographyTTF1_create_glyf(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    IEcoTypographyTTF1glyf* pIglyf = 0;
    uint16_t result = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    result = createCEcoTypographyTTF1glyf((IEcoUnknown*)pCMe->m_pISys, 0, (IEcoTypographyTTF1glyf**)&pIglyf);

    return pIglyf;
}

/*
 *
 * <сводка>
 *   Функция create_maxp
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoTypographyTTF1maxp* CEcoTypographyTTF1_create_maxp(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    IEcoTypographyTTF1maxp* pImaxp = 0;
    uint16_t result = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    result = createCEcoTypographyTTF1maxp((IEcoUnknown*)pCMe->m_pISys, 0, (IEcoTypographyTTF1maxp**)&pImaxp);

    return pImaxp;
}

/*
 *
 * <сводка>
 *   Функция create_loca
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoTypographyTTF1loca* CEcoTypographyTTF1_create_loca(/* in */ struct IEcoTypographyTTF1* me) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    IEcoTypographyTTF1loca* pIloca = 0;
    uint16_t result = 0;

    /* Проверка указателя */
    if (me == 0 ) {
        return 0;
    }

    result = createCEcoTypographyTTF1loca((IEcoUnknown*)pCMe->m_pISys, 0, (IEcoTypographyTTF1loca**)&pIloca);

    return pIloca;
}

/*
 *
 * <сводка>
 *   Функция Load
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
IEcoTypographyTTF1FontFile* CEcoTypographyTTF1_Load(/* in */ struct IEcoTypographyTTF1* me, /* in */ char_t* fileName) {
	int16_t resultQ = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
	IEcoMemoryAllocator1* pIMem = 0;
    int16_t result = 0;
    IEcoTypographyTTF1FontFile* pIFontFile = 0;
    IEcoTypographyTTF1TableRecord* pITableRecord = 0;
	IEcoTypographyTTF1TableRecord* glyfRecord = 0;
	IEcoTypographyTTF1TableRecord* cmapRecord = 0;
    IEcoList1* pITableDirectory = 0;
    IEcoTypographyTTF1head* pIhead = 0;
    IEcoTypographyTTF1cmap* pIcmap = 0;
    IEcoTypographyTTF1glyf* pIglyf = 0;
    IEcoTypographyTTF1maxp* pImaxp = 0;
    IEcoTypographyTTF1loca* pIloca = 0;
    char_t buffer[256] = {0};
    uint32_t len = 4;
    uint32_t offsetTableDirectory = 0;
    uint32_t offsetTable = 0;
	uint32_t offsetGlyph = 0;
    uint16_t numTables = 0;
	uint16_t numGlyphs = 0;
	uint16_t xIndex = 0;
    int16_t indexToLocFormat = 0;
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* pTableDirectoryDescriptor = (ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR*)&buffer;
	ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR* glyphHeaderDescriptor = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT* glyphSimpleContent = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT* glyphCompositeContent = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_COMPONENT_CONTENT* glyphCompositeContentComponent = 0;
	ECO_TRUE_TYPE_FONT_1_CMAP_DESCRIPTOR* cmapDescriptor = 0;
	ECO_TRUE_TYPE_FONT_1_ENCODING_RECORD_DESCRIPTOR* buffEncodingRecord = 0;
	IEcoList1* buffArray = 0;
	int16_t* buffInt;
	uint16_t* buffUInt;
	int16_t buffIntVal;
	uint8_t* buffUint8;
	uint16_t arrayReadIndex = 0;
	uint16_t coordArrayReadIndex = 0;
	uint16_t coordinatesReadIndex = 0;
	uint32_t pointer = 0;
	int16_t numOfPoints;
	int32_t sizeOfLastPointsArray;
	uint8_t isCoordRepeatsOrNegative;
	uint8_t isCoordShort;
	uint8_t isArgumentsAreWords;
	uint8_t isArgumentsAreSigned;
	int16_t lastCoord;
	uint8_t flag;
	uint32_t lastLen;
	uint8_t isSetFlagRepeat = 0;
	uint8_t timesToFlagRepeat = 0;
	uint8_t isMoreCompositeComponentsAhead = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_COMPONENT_CONTENT* glyphCompositeContentComponentBuf = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT* glyphCompositeContentBuf = 0;
	uint32_t addressesArrayIndex = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS* componentAddress = 0;

	result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &GID_IEcoSystem1, (void **)&pISys);

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    if (fileName != 0 && pCMe->m_pIFileManager != 0) {
        pCMe->m_pIFile = pCMe->m_pIFileManager->pVTbl->Open(pCMe->m_pIFileManager, fileName);
    }

    /* Чтение */
    if (pCMe->m_pIFile != 0) {
        len = sizeof(ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR);
        if ((result = pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffer, &len)) == 0) {
            pIFontFile = me->pVTbl->createFontFile(me);
            pIFontFile->pVTbl->set_Descriptor(pIFontFile, pTableDirectoryDescriptor);
            result = pCMe->m_pIBus->pVTbl->QueryComponent(pCMe->m_pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**) &pITableDirectory);

            numTables = byteswap_uint16_t(pTableDirectoryDescriptor->numTables);
            while (numTables > 0) {
                numTables--;
                pITableRecord = me->pVTbl->createTableRecord(me);
                len = sizeof(ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR);
                if ((result = pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, pITableRecord->pVTbl->get_Descriptor(pITableRecord), &len)) == 0) {
                    offsetTableDirectory = pCMe->m_pIFile->pVTbl->get_Pointer(pCMe->m_pIFile);
                    /* head */
                    if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x64616568) {
                        pIhead = me->pVTbl->create_head(me);
                        offsetTable = byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->offset);
                        pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, offsetTable);
                        len = sizeof(ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR);
                        if ((result = pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, pIhead->pVTbl->get_Descriptor(pIhead), &len)) == 0) {
                            indexToLocFormat = byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->indexToLocFormat);
                            pITableRecord->pVTbl->set_Table(pITableRecord, (IEcoUnknown*)pIhead);
                        }
                    }
                    /* loca */
                    if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x61636F6C) {
                        pIloca = me->pVTbl->create_loca(me);
                        offsetTable = byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->offset);
                        pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, offsetTable);
                        len = byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->length);
                        pIloca->pVTbl->set_TableData(pIloca, 0, len);
                        if ((result = pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, pIloca->pVTbl->get_TableData(pIloca), &len)) == 0) {
                            pIloca->pVTbl->set_OffsettFormat(pIloca, indexToLocFormat);
                            pITableRecord->pVTbl->set_Table(pITableRecord, (IEcoUnknown*)pIloca);
                        }
                    }
                    /* cmap */
                    if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x70616D63) {
                        pIcmap = me->pVTbl->create_cmap(me);
						cmapRecord = pITableRecord;
                        cmapRecord->pVTbl->set_Table(pITableRecord, (IEcoUnknown*)pIcmap);
                    }
                    /* glyf */
                    if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x66796C67) {
						pIglyf = me->pVTbl->create_glyf(me);
						glyfRecord = pITableRecord;
						glyfRecord->pVTbl->set_Table(pITableRecord, (IEcoUnknown*)pIglyf);
                    }
                    /* maxp */
                    if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x7078616D) {
                        pImaxp = me->pVTbl->create_maxp(me);
                        offsetTable = byteswap_uint32_t(pITableRecord->pVTbl->get_Descriptor(pITableRecord)->offset);
                        pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, offsetTable);
                        len = sizeof(ECO_TRUE_TYPE_FONT_1_MAXP_DESCRIPTOR);
                        if ((result = pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, pImaxp->pVTbl->get_Descriptor(pImaxp), &len)) == 0) {
                            pITableRecord->pVTbl->set_Table(pITableRecord, (IEcoUnknown*)pImaxp);
                        }
                    }

                    pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, offsetTableDirectory);

                    pITableDirectory->pVTbl->Add(pITableDirectory, pITableRecord);
                }
            }

			//start to read cmap
			if (pIcmap != 0){

				len = sizeof(ECO_TRUE_TYPE_FONT_1_CMAP_DESCRIPTOR);
				cmapDescriptor = (ECO_TRUE_TYPE_FONT_1_CMAP_DESCRIPTOR*) pIMem->pVTbl->Alloc(pIMem, len);
				offsetTable = byteswap_uint32_t(cmapRecord->pVTbl->get_Descriptor(cmapRecord)->offset);
				pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, offsetTable);
				pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, cmapDescriptor, &len);

				cmapDescriptor->version = byteswap_int16_t(cmapDescriptor->version);
				cmapDescriptor->numberSubtables = byteswap_int16_t(cmapDescriptor->numberSubtables);
				pIcmap->pVTbl->set_Descriptor(pIcmap, cmapDescriptor);

				offsetTable += len;

				len = sizeof(ECO_TRUE_TYPE_FONT_1_ENCODING_RECORD_DESCRIPTOR);
				pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&buffArray);
				for (arrayReadIndex = 0; arrayReadIndex < cmapDescriptor->numberSubtables; arrayReadIndex ++){
					buffEncodingRecord = (ECO_TRUE_TYPE_FONT_1_ENCODING_RECORD_DESCRIPTOR*)pIMem->pVTbl->Alloc(pIMem, len);
					pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, offsetTable);
					pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffEncodingRecord, &len);
					buffEncodingRecord->platformID = byteswap_int16_t(buffEncodingRecord->platformID);
					buffEncodingRecord->encodingID = byteswap_int16_t(buffEncodingRecord->encodingID);
					buffEncodingRecord->subtableOffset = byteswap_uint32_t(buffEncodingRecord->subtableOffset);
					offsetTable += len;
					buffArray->pVTbl->Add(buffArray, buffEncodingRecord);
				}

			}

			//start to read glyfs 
			numGlyphs = byteswap_uint16_t(pImaxp->pVTbl->get_Descriptor(pImaxp)->numGlyphs);
			if (pIglyf != 0){
				for (xIndex = 0; xIndex < numGlyphs; xIndex++){
					offsetGlyph = pIloca->pVTbl->get_Offset32(pIloca, xIndex);
					len = pIloca->pVTbl->get_Offset32(pIloca, xIndex + 1) - offsetGlyph;
					glyphHeaderDescriptor = (ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR*) pIMem->pVTbl->Alloc(pIMem, len);
					if(len != 0){
						offsetTable = byteswap_uint32_t(glyfRecord->pVTbl->get_Descriptor(glyfRecord)->offset);
						offsetTable = offsetTable + offsetGlyph;
						pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, offsetTable);
						pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, glyphHeaderDescriptor, &len);

						glyphHeaderDescriptor->numberOfContours = byteswap_int16_t(glyphHeaderDescriptor->numberOfContours);
						glyphHeaderDescriptor->xMax = byteswap_int16_t(glyphHeaderDescriptor->xMax);
						glyphHeaderDescriptor->xMin = byteswap_int16_t(glyphHeaderDescriptor->xMin);
						glyphHeaderDescriptor->yMax = byteswap_int16_t(glyphHeaderDescriptor->yMax);
						glyphHeaderDescriptor->yMin = byteswap_int16_t(glyphHeaderDescriptor->yMin);

						if (glyphHeaderDescriptor->numberOfContours > 0){
							
							glyphSimpleContent = (ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT*) pIMem->pVTbl->Alloc(pIMem, len);

							pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&buffArray);

							pointer = offsetTable + sizeof(ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR);
							len = sizeof(int16_t);
							for (arrayReadIndex = 0; arrayReadIndex < glyphHeaderDescriptor->numberOfContours; arrayReadIndex ++){
								pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer + (sizeof(int16_t) * arrayReadIndex));
								buffInt = (int16_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(int16_t));
								pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
								*buffInt = byteswap_int16_t(*buffInt);
								buffArray->pVTbl->Add(buffArray, buffInt);
							}
							glyphSimpleContent->endPtsOfContours = (IEcoList1*) buffArray;

							pointer = pointer + (sizeof(int16_t) * arrayReadIndex);
							pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);
							buffInt = (int16_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(int16_t));
							pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
							*buffInt = byteswap_int16_t(*buffInt);
							glyphSimpleContent->instructionLength = *buffInt;

							if(glyphSimpleContent->instructionLength > 0){
								pointer = pointer + sizeof(int16_t);
								len = sizeof(uint8_t);
								pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&buffArray);
								for (arrayReadIndex = 0; arrayReadIndex < glyphSimpleContent->instructionLength; arrayReadIndex ++){
									pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer + (sizeof(uint8_t) * arrayReadIndex));
									buffUint8 = (uint8_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(uint8_t));
									pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffUint8, &len);
									buffArray->pVTbl->Add(buffArray, buffUint8);
								}
								glyphSimpleContent->instructions = (IEcoList1*) buffArray;
								pointer = pointer + sizeof(uint8_t) * arrayReadIndex;
							} else {
								pointer = pointer + sizeof(int16_t);
							}

							sizeOfLastPointsArray = glyphSimpleContent->endPtsOfContours->pVTbl->Count(glyphSimpleContent->endPtsOfContours);
							numOfPoints = *(int16_t*) glyphSimpleContent->endPtsOfContours->pVTbl->Item(glyphSimpleContent->endPtsOfContours, sizeOfLastPointsArray - 1);

							len = sizeof(uint8_t);
							pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&buffArray);

							for (arrayReadIndex = 0; arrayReadIndex <= numOfPoints; arrayReadIndex ++){
								if((!isSetFlagRepeat && !timesToFlagRepeat) || 1 == 1){
									buffUint8 = (uint8_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(uint8_t));
									pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer + (sizeof(uint8_t) * arrayReadIndex));
									pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffUint8, &len);
									isSetFlagRepeat = CHECK_BIT(flag, 3);
									buffArray->pVTbl->Add(buffArray, buffUint8);
								} else if (isSetFlagRepeat){
									pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer + (sizeof(uint8_t) * arrayReadIndex));
									pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffUint8, &len);
									timesToFlagRepeat = *buffUint8 - 1;
									buffArray->pVTbl->Add(buffArray, buffUint8);
									isSetFlagRepeat = 0;
								} else {
									timesToFlagRepeat = *buffUint8 - 1;
									buffArray->pVTbl->Add(buffArray, buffUint8);
								}
							}

							glyphSimpleContent->flags = (IEcoList1*) buffArray;
							pointer = pointer + sizeof(uint8_t) * arrayReadIndex;

							lastLen = sizeof(uint8_t);
							coordArrayReadIndex = 0;
							pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&buffArray);
							for (arrayReadIndex = 0; arrayReadIndex <= numOfPoints; arrayReadIndex ++){
								flag = *(uint8_t*) glyphSimpleContent->flags->pVTbl->Item(glyphSimpleContent->flags, arrayReadIndex);
								buffInt = (int16_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(int16_t));
								isCoordRepeatsOrNegative = CHECK_BIT(flag, 4);
								isCoordShort = CHECK_BIT(flag, 1);
								if (!isCoordShort && isCoordRepeatsOrNegative) {
									*buffInt = 0;
								} else if(isCoordShort) {
									len = sizeof(uint8_t);
									pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);
									pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
									if(!isCoordRepeatsOrNegative) {
										*buffInt = *buffInt * -1;
									}
									lastLen = sizeof(uint8_t);
									
									coordArrayReadIndex++;
									pointer = pointer + len;
								} else {
									len = sizeof(int16_t);
									pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);
									pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
									lastLen = sizeof(int16_t);
									*buffInt = byteswap_int16_t(*buffInt);
									coordArrayReadIndex++;
									pointer = pointer + len;
								}

								buffArray->pVTbl->Add(buffArray, buffInt);
							}
							glyphSimpleContent->xCoordinates = (IEcoList1*) buffArray;

							coordArrayReadIndex = 0;
							pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&buffArray);
							for (arrayReadIndex = 0; arrayReadIndex <= numOfPoints; arrayReadIndex ++){
								flag = *(uint8_t*) glyphSimpleContent->flags->pVTbl->Item(glyphSimpleContent->flags, arrayReadIndex);
								buffInt = (int16_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(int16_t));
								isCoordRepeatsOrNegative = CHECK_BIT(flag, 5);
								isCoordShort = CHECK_BIT(flag, 2);
								if (!isCoordShort && isCoordRepeatsOrNegative) {
									*buffInt = 0;
								} else if(isCoordShort) {
									len = sizeof(uint8_t);
									pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);
									pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
									if(!isCoordRepeatsOrNegative) {
										*buffInt = *buffInt * -1;
									}
									lastLen = sizeof(uint8_t);
									
									coordArrayReadIndex++;
									pointer = pointer + len;
								} else {
									len = sizeof(int16_t);
									pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);
									pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
									lastLen = sizeof(int16_t);
									*buffInt = byteswap_int16_t(*buffInt);
									coordArrayReadIndex++;
									pointer = pointer + len;
								}

								buffArray->pVTbl->Add(buffArray, buffInt);
							}
							glyphSimpleContent->yCoordinates = (IEcoList1*) buffArray;
				
						} else if (byteswap_int16_t(glyphHeaderDescriptor->numberOfContours) < 0) {
					
							glyphCompositeContent = (ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT*) pIMem->pVTbl->Alloc(pIMem, len);
							pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&buffArray);

							pointer = offsetTable + sizeof(ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR);
							pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);
							isMoreCompositeComponentsAhead = 1;
							pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&buffArray);

							while (isMoreCompositeComponentsAhead) {
								len = sizeof(ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_COMPONENT_CONTENT);
								glyphCompositeContentComponent = (ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_COMPONENT_CONTENT*) pIMem->pVTbl->Alloc(pIMem, len);
								len = sizeof(uint16_t);

								buffInt = (int16_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(int16_t));
								pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
								*buffInt = byteswap_int16_t(*buffInt);
								glyphCompositeContentComponent -> flags = *buffInt;

								isMoreCompositeComponentsAhead = CHECK_BIT(glyphCompositeContentComponent -> flags, 5);

								pointer = pointer + len;
								pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);

								buffUInt = (uint16_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(uint16_t));
								pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffUInt, &len);
								*buffUInt = byteswap_uint16_t(*buffUInt);
								glyphCompositeContentComponent ->glyphIndex = *buffUInt;

								pointer = pointer + len;
								pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);

								isArgumentsAreWords = CHECK_BIT(glyphCompositeContentComponent -> flags, 0);
								isArgumentsAreSigned = CHECK_BIT(glyphCompositeContentComponent -> flags, 1);
								if (isArgumentsAreWords && isArgumentsAreSigned) {
									len = sizeof(int16_t);
								} else if (!isArgumentsAreWords && isArgumentsAreSigned) {
									len = sizeof(int8_t);
								} else if (!isArgumentsAreWords && !isArgumentsAreSigned) {
									len = sizeof(uint8_t);
								}

								buffInt = (int16_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(int16_t));
								pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
								if (isArgumentsAreWords && isArgumentsAreSigned) {
									*buffInt = byteswap_int16_t(*buffInt);
								}
								glyphCompositeContentComponent ->argument1 = *buffInt;

								pointer = pointer + len;
								pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);

								buffInt = (int16_t*) pIMem->pVTbl->Alloc(pIMem, sizeof(int16_t));
								pCMe->m_pIFile->pVTbl->Read(pCMe->m_pIFile, buffInt, &len);
								if (isArgumentsAreWords && isArgumentsAreSigned) {
									*buffInt = byteswap_int16_t(*buffInt);
								}
								glyphCompositeContentComponent ->argument2 = *buffInt;

								pointer = pointer + len;
								pCMe->m_pIFile->pVTbl->set_Pointer(pCMe->m_pIFile, pointer);

								buffArray->pVTbl->Add(buffArray, glyphCompositeContentComponent);
							}
							glyphCompositeContent->components = (IEcoList1*) buffArray;
						}

						len = sizeof(ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS);
						componentAddress = (ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS*) pIMem->pVTbl->Alloc(pIMem, len);
						if (glyphHeaderDescriptor->numberOfContours > 0) {
							addressesArrayIndex = pIglyf->pVTbl->set_SimpleContent(pIglyf, xIndex, glyphSimpleContent);
							componentAddress->isSimple = 1;
							componentAddress->indexInArray = addressesArrayIndex;
						} else {
							addressesArrayIndex = pIglyf->pVTbl->set_CompositeContent(pIglyf, xIndex, glyphCompositeContent);
							componentAddress->isSimple = 0;
							componentAddress->indexInArray = addressesArrayIndex;
						}
						
					}
					pIglyf->pVTbl->set_ComponentAddress(pIglyf, componentAddress);
					pIglyf->pVTbl->set_Descriptor(pIglyf, xIndex, glyphHeaderDescriptor);
				}
			}
			pITableDirectory->pVTbl->Add(pITableDirectory, glyfRecord);
            pIFontFile->pVTbl->set_TableDirectory(pIFontFile, pITableDirectory);
			pIFontFile->pVTbl->set_GlyfTable(pIFontFile, pIglyf);
        }
    }

    return pIFontFile;
}

/*
 *
 * <сводка>
 *   Функция Save
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1_Save(/* in */ struct IEcoTypographyTTF1* me, /* in */ IEcoTypographyTTF1FontFile* pIFontFile, /* in */ char_t* fileName) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
	uint32_t size = sizeof(ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR);
	ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor = pIFontFile->pVTbl->get_Descriptor(pIFontFile);
    if (fileName != 0 && pCMe->m_pIFileManager != 0) {
		pCMe->m_pIFileManager->pVTbl->Create(pCMe->m_pIFileManager, fileName);
        pCMe->m_pIFile = pCMe->m_pIFileManager->pVTbl->Open(pCMe->m_pIFileManager, fileName);

		pCMe->m_pIFile->pVTbl->Write(pCMe->m_pIFile, descriptor, &size);
		pCMe->m_pIFile->pVTbl->Close(pCMe->m_pIFile);
    }

    /* Чтение */
    if (pCMe->m_pIFile != 0) {
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t initCEcoTypographyTTF1(/*in*/ struct IEcoTypographyTTF1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение интерфейса по работе со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void**) &pCMe->m_pIStr);
    /* Проверка */
    if (result != 0 || pCMe->m_pIStr == 0) {
        /* Освобождение в случае ошибки */
        return result;
    }

    /* Получение интерфейса управление файлами */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFileSystemManagement1, 0, &IID_IEcoFileManager1, (void**) &pCMe->m_pIFileManager);

    if (result != 0 || pCMe->m_pIFileManager == 0) {
        /* Освобождение в случае ошибки */
        return result;
    }

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/* Create Virtual Table */
IEcoTypographyTTF1VTbl g_xFC300438926D4270B6846AE055E3534AVTbl = {
    CEcoTypographyTTF1_QueryInterface,
    CEcoTypographyTTF1_AddRef,
    CEcoTypographyTTF1_Release,
    CEcoTypographyTTF1_createFontFile,
    CEcoTypographyTTF1_createTableRecord,
    CEcoTypographyTTF1_create_head,
    CEcoTypographyTTF1_create_cmap,
    CEcoTypographyTTF1_create_glyf,
    CEcoTypographyTTF1_create_maxp,
    CEcoTypographyTTF1_create_loca,
    CEcoTypographyTTF1_Load,
    CEcoTypographyTTF1_Save
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
int16_t createCEcoTypographyTTF1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1** ppIEcoTypographyTTF1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoTypographyTTF1* pCMe = 0;

    /* Проверка указателей */
    if (ppIEcoTypographyTTF1 == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoTypographyTTF1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoTypographyTTF1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;
    pCMe->m_pIBus = pIBus;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoTypographyTTF1 */
    pCMe->m_pVTblIEcoTypographyTTF1 = &g_xFC300438926D4270B6846AE055E3534AVTbl;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoTypographyTTF1 = (IEcoTypographyTTF1*)pCMe;

    /* Освобождение */

    return 0;
}

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
void deleteCEcoTypographyTTF1(/* in */ IEcoTypographyTTF1* pIEcoTypographyTTF1) {
    CEcoTypographyTTF1* pCMe = (CEcoTypographyTTF1*)pIEcoTypographyTTF1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoTypographyTTF1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
