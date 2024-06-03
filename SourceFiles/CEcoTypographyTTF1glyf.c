/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1glyf
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoTypographyTTF1glyf
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

/* Подключаемые заголовки файлов */
#include "CEcoTypographyTTF1glyf.h"
#include "CEcoTypographyTTF1loca.h"
#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "byteswap.h"

#define CHECK_BIT(var,pos) (((var)>>(pos)) & 1)
/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoTypographyTTF1glyf
 * </описание>
 *
 */
int16_t CEcoTypographyTTF1glyf_QueryInterface(/* in */ struct IEcoTypographyTTF1glyf* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoTypographyTTF1glyf) ) {
        *ppv = &pCMe->m_pVTblIglyf;
        pCMe->m_pVTblIglyf->AddRef((IEcoTypographyTTF1glyf*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIglyf;
        pCMe->m_pVTblIglyf->AddRef((IEcoTypographyTTF1glyf*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoTypographyTTF1glyf
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1glyf_AddRef(/* in */ struct IEcoTypographyTTF1glyf* me) {
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;

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
 *   Функция Release для интерфейса IEcoTypographyTTF1glyf
 * </описание>
 *
 */
uint32_t CEcoTypographyTTF1glyf_Release(/* in */ struct IEcoTypographyTTF1glyf* me) {
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoTypographyTTF1glyf((IEcoTypographyTTF1glyf*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

IEcoList1* CEcoTypographyTTF1glyf_get_GlyfPoints(/* in */ struct IEcoTypographyTTF1glyf* me, int index) {
	IEcoSystem1* m_pISys;
	CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;
	IEcoMemoryAllocator1* pIMem;
	IEcoInterfaceBus1* pIBus;
	IEcoList1* listOfPoints = 0;
	int16_t numOfPoints = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_POINT* buffPoint = 0;
	uint16_t i = 0;
	uint16_t j = 0;
	uint8_t flag = 0;
	int16_t x = 0;
	int16_t y = 0;
	uint8_t isOnCurve = 0;
	int16_t numOfContours = 0;
	int16_t contourNumBuf = 0;
	int16_t startPointBuf = 0;

	ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT* sContent = me->pVTbl->get_SimpleContent(me, index);
	ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR* descriptor = me->pVTbl->get_Descriptor(me, index);
	numOfContours = descriptor->numberOfContours;

	m_pISys = pCMe->m_pISys;
	m_pISys->pVTbl->QueryInterface(m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
	pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&listOfPoints);
	pIMem = pCMe->m_pIMem;

	if(descriptor->numberOfContours > 0){
		
		numOfPoints = *(int16_t*) sContent->endPtsOfContours->pVTbl->Item(sContent->endPtsOfContours, numOfContours - 1);
		
		for (i = 0; i <= numOfPoints; i++){
			flag = *(uint8_t*) sContent->flags->pVTbl->Item(sContent->flags, i);
			buffPoint = (ECO_TRUE_TYPE_FONT_1_GLYPH_POINT*) pIMem->pVTbl->Alloc(pIMem, sizeof(ECO_TRUE_TYPE_FONT_1_GLYPH_POINT));
			
			buffPoint->isOnCurve = CHECK_BIT(flag, 0);
			for (j = 0; j < descriptor->numberOfContours; j++){
				if (j == 0) {
					startPointBuf = 0;
				} else {
					startPointBuf = (*(int16_t*)sContent->endPtsOfContours->pVTbl->Item(sContent->endPtsOfContours, j - 1)) + 1;
				}

				if (j == 0){
					buffPoint->contourNum = j;
				} else if (startPointBuf <= i) {
					buffPoint->contourNum = j;
				} else {continue;}
			}
			buffPoint->x = *(int16_t*) sContent->xCoordinates->pVTbl->Item(sContent->xCoordinates, i);
			buffPoint->y = *(int16_t*) sContent->yCoordinates->pVTbl->Item(sContent->yCoordinates, i);

			listOfPoints->pVTbl->Add(listOfPoints, buffPoint);
		}
	}

	return listOfPoints;
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
ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR* CEcoTypographyTTF1glyf_get_Descriptor(/* in */ struct IEcoTypographyTTF1glyf* me, int index) {
	ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR* dsc = 0;
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;
	dsc = (ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR*) pCMe->m_Descriptors->pVTbl->Item(pCMe->m_Descriptors, index);
	return dsc;
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
void CEcoTypographyTTF1glyf_set_Descriptor(/* in */ struct IEcoTypographyTTF1glyf* me, int index, /* in */ ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR* descriptor) {
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;

    if (me == 0 || descriptor == 0) {
        return;
    }

	if(pCMe->m_Descriptors->pVTbl->Count(pCMe->m_Descriptors) == 0){
		pCMe->m_Descriptors->pVTbl->Add(pCMe->m_Descriptors, descriptor);
	} else {
		pCMe->m_Descriptors->pVTbl->Add(pCMe->m_Descriptors, descriptor);
	}
}

ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT* CEcoTypographyTTF1glyf_get_SimpleContent(/* in */ struct IEcoTypographyTTF1glyf* me, int index) {
	ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT* content = 0;
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;
	uint32_t contentIndex = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS* address = 0;
	address = (ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS*) pCMe->m_ComponentsAddresses->pVTbl->Item(pCMe->m_ComponentsAddresses, index);
	contentIndex = address->indexInArray;
	content = (ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT*) pCMe->m_SimpleContents->pVTbl->Item(pCMe->m_SimpleContents, contentIndex);
	return content;
}

uint32_t CEcoTypographyTTF1glyf_set_SimpleContent(/* in */ struct IEcoTypographyTTF1glyf* me, int index,/* in */ ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT* content) {
	CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;
	uint32_t arrayIndex = 0; 
    if (me == 0 || content == 0) {
        return;
    }

	if(pCMe->m_SimpleContents->pVTbl->Count(pCMe->m_SimpleContents) == 0){
		arrayIndex = pCMe->m_SimpleContents->pVTbl->Add(pCMe->m_SimpleContents, content);
	} else {
		arrayIndex = pCMe->m_SimpleContents->pVTbl->Add(pCMe->m_SimpleContents, content);
	}

	return arrayIndex;
}

ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT* CEcoTypographyTTF1glyf_get_CompositeContent(/* in */ struct IEcoTypographyTTF1glyf* me, int index) {
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT* content = 0;
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;
	uint32_t contentIndex = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS* address = 0;
	address = (ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS*) pCMe->m_ComponentsAddresses->pVTbl->Item(pCMe->m_ComponentsAddresses, index);
	contentIndex = address->indexInArray;
	content = (ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT*) pCMe->m_CompositeContents->pVTbl->Item(pCMe->m_CompositeContents, contentIndex);
	return content;
}

uint32_t CEcoTypographyTTF1glyf_set_CompositeContent(/* in */ struct IEcoTypographyTTF1glyf* me, int index,/* in */ ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT* content) {
	CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;
	uint32_t arrayIndex = 0; 

    if (me == 0 || content == 0) {
        return;
    }

	if(pCMe->m_CompositeContents->pVTbl->Count(pCMe->m_CompositeContents) == 0){
		arrayIndex = pCMe->m_CompositeContents->pVTbl->Add(pCMe->m_CompositeContents, content);
	} else {
		arrayIndex = pCMe->m_CompositeContents->pVTbl->Add(pCMe->m_CompositeContents, content);
	}

	return arrayIndex;
}

ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS* CEcoTypographyTTF1glyf_get_ComponentAddress(/* in */ struct IEcoTypographyTTF1glyf* me, int index) {
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS* content = 0;
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;
	content = (ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS*) pCMe->m_ComponentsAddresses->pVTbl->Item(pCMe->m_ComponentsAddresses, index);
	return content;
}

void CEcoTypographyTTF1glyf_set_ComponentAddress(/* in */ struct IEcoTypographyTTF1glyf* me, /* in */ ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS* content) {
	CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;

    if (me == 0 || content == 0) {
        return;
    }

	if(pCMe->m_ComponentsAddresses->pVTbl->Count(pCMe->m_ComponentsAddresses) == 0){
		pCMe->m_ComponentsAddresses->pVTbl->Add(pCMe->m_ComponentsAddresses, content);
	} else {
		pCMe->m_ComponentsAddresses->pVTbl->Add(pCMe->m_ComponentsAddresses, content);
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
IEcoList1* CEcoTypographyTTF1glyf_get_TableDirectory(/* in */ struct IEcoTypographyTTF1glyf* me) {
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;

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
void CEcoTypographyTTF1glyf_set_TableDirectory(/* in */ struct IEcoTypographyTTF1glyf* me, /* in */ IEcoList1* pIRecords) {
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)me;

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
IEcoTypographyTTF1glyfVTbl g_xF46473B7CFA645149517DE19AE61DE48VTbl = {
    CEcoTypographyTTF1glyf_QueryInterface,
    CEcoTypographyTTF1glyf_AddRef,
    CEcoTypographyTTF1glyf_Release,
    CEcoTypographyTTF1glyf_get_Descriptor,
    CEcoTypographyTTF1glyf_set_Descriptor,
	CEcoTypographyTTF1glyf_get_SimpleContent,
    CEcoTypographyTTF1glyf_set_SimpleContent,
	CEcoTypographyTTF1glyf_get_CompositeContent,
    CEcoTypographyTTF1glyf_set_CompositeContent,
	CEcoTypographyTTF1glyf_get_ComponentAddress,
    CEcoTypographyTTF1glyf_set_ComponentAddress,
    CEcoTypographyTTF1glyf_get_TableDirectory,
    CEcoTypographyTTF1glyf_set_TableDirectory,
	CEcoTypographyTTF1glyf_get_GlyfPoints

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
int16_t createCEcoTypographyTTF1glyf(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1glyf** ppIMember) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoTypographyTTF1glyf* pCMe = 0;

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
    pCMe = (CEcoTypographyTTF1glyf*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoTypographyTTF1glyf));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoTypographyTTF1glyf */
    pCMe->m_pVTblIglyf = &g_xF46473B7CFA645149517DE19AE61DE48VTbl;

	pCMe->m_TableDirectory = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&pCMe->m_TableDirectory);
    if (result != 0 || pCMe->m_TableDirectory == 0) {
        return result;
    }

    /* Создание экземпляра для работы со строкой */
    pCMe->m_pIString = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pCMe->m_pIString);
    if (result != 0 || pCMe->m_pIString == 0) {
        return result;
    }

	pCMe->m_Descriptors = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&pCMe->m_Descriptors);
    if (result != 0 || pCMe->m_Descriptors == 0) {
        return result;
    }

	pCMe->m_SimpleContents = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&pCMe->m_SimpleContents);
    if (result != 0 || pCMe->m_SimpleContents == 0) {
        return result;
    }

	pCMe->m_CompositeContents = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&pCMe->m_CompositeContents);
    if (result != 0 || pCMe->m_CompositeContents == 0) {
        return result;
    }

    pCMe->m_ComponentsAddresses = 0;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void **)&pCMe->m_ComponentsAddresses);
    if (result != 0 || pCMe->m_ComponentsAddresses == 0) {
        return result;
    }


    /* Возврат указателя на интерфейс */
    *ppIMember = (IEcoTypographyTTF1glyf*)pCMe;

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
void deleteCEcoTypographyTTF1glyf(/* in */ IEcoTypographyTTF1glyf* pIMember) {
    CEcoTypographyTTF1glyf* pCMe = (CEcoTypographyTTF1glyf*)pIMember;
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
