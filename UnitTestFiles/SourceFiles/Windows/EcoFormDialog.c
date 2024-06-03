/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoFormDialog
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

#include "windows.h"
#include "commctrl.h"
#include "commdlg.h"
#include "resource.h"
#pragma comment(lib, "user32")
#pragma comment(lib, "comctl32.lib")

/* Eco OS */
#include "IEcoSystem1.h"
#include "IEcoList1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoFileSystemManagement1.h"
#include "EcoFormDialog.h"

/* Указатель на интерфейс для работы с TTF файлом */
IEcoTypographyTTF1FontFile* g_pIFontFile = 0;

uint32_t g_GlyphIndex = 36;

/*
 *
 * <сводка>
 *   Функция RenderGlyph
 * </сводка>
 *
 * <описание>
 *   Функция RenderGlyph
 * </описание>
 *
 */
BOOL CALLBACK RenderGlyph(HWND hwndPictureBox, IEcoTypographyTTF1FontFile* pIFontFile) { 
    BITMAPINFO xBmi = {0};
    byte_t* buffer = NULL;
    uint32_t size = 0;
    HBITMAP hBmp;
    HDC winDC;
    HDC memoryDC;
    HBITMAP hOldBitmap;
    HGDIOBJ hPen = NULL;
    HGDIOBJ hPenOld; 
    LOGBRUSH lb;
	IEcoList1* points;
    IEcoTypographyTTF1TableRecord* pITableRecord = 0;
    IEcoList1* pITableDirectory = 0;
    IEcoTypographyTTF1head* pIhead = 0;
    IEcoTypographyTTF1cmap* pIcmap = 0;
    IEcoTypographyTTF1glyf* pIglyf = 0;
    IEcoTypographyTTF1maxp* pImaxp = 0;
	ECO_TRUE_TYPE_FONT_1_GLYPH_POINT* point;
	ECO_TRUE_TYPE_FONT_1_GLYPH_POINT* pointStart = (ECO_TRUE_TYPE_FONT_1_GLYPH_POINT*)malloc(sizeof(ECO_TRUE_TYPE_FONT_1_GLYPH_POINT));
	ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT* sContent; 
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT* cContent;
	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_COMPONENT_CONTENT* cCompContent;
    uint32_t index = 0;
	uint32_t hindex = 0;
	int16_t jindex = 0;
	int16_t numOfContours = 0;
    uint32_t width = 2000;
    uint32_t height = 2000;
    int16_t ttf_x_max = 0;
	int16_t x = 0;
	int16_t y = 0;
    int16_t ttf_y_max = 0;
    int16_t ttf_x_min = 0;
    int16_t ttf_y_min = 0;
    int16_t glyph_width = 0;
    int16_t glyph_height = 0;
    float_t x_ratio = 1.0f;
    float_t y_ratio = 1.0f;
    XFORM xForm; 
    RECT rect = { 0, 0, width, height };
    ECO_TRUE_TYPE_FONT_1_GLYPH_POINT* last = 0;
    POINT xGID_16[4] = {83, 535, 517, 0, 0, -151, -517, 0};
    uint32_t sizeGID_16 = 4;
    POINT xGID_573[23] = {1125,  1356,    5, -317,  -39,   0,    -4, 96,
                          -74,   116, -107,   31, -101,   0,  -380,  0,
                            0, -1035,    0, -134,   69, -72,   125, -4,
                            0,   -37, -582,    0,    0,  37,   126,  4,
                           70,    72,    0,  134,    0, 862,     0, 134,
                          -70,    72, -126,    4,    0,  37};
    uint32_t sizeGID_573 = 23;
    POINT* ptrGlyph = 0;
	int16_t endPointBuf = 0;
	int16_t startPointBuf = 0;
	uint8_t isGlyfComposite = 0;
	uint8_t numOfGlyfs = 0;
	uint16_t bufGlyfIndex = 0;

    /* хардкод */
    if (g_GlyphIndex == 573) {
        ptrGlyph = xGID_573;
        size = sizeGID_573;
    }
    else {
        ptrGlyph = xGID_16;
        size = sizeGID_16;
    }

    pITableDirectory = pIFontFile->pVTbl->get_TableDirectory(pIFontFile);
    for (index = 0; index < pITableDirectory->pVTbl->Count(pITableDirectory); index++) {
        pITableRecord = (IEcoTypographyTTF1TableRecord*)pITableDirectory->pVTbl->Item(pITableDirectory, index);
        if ( pITableRecord->pVTbl->get_Descriptor(pITableRecord)->tag == 0x64616568) {
            pIhead = (IEcoTypographyTTF1head*)pITableRecord->pVTbl->get_Table(pITableRecord);
        }
    }
	pIglyf = pIFontFile->pVTbl->get_GlyfTable(pIFontFile);

    ttf_x_max = byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->xMax);
    ttf_y_max = byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->yMax);
    ttf_x_min = byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->xMin);
    ttf_y_min = byteswap_int16_t(pIhead->pVTbl->get_Descriptor(pIhead)->yMin);
    glyph_width = ttf_x_max - ttf_x_min;
    glyph_height = ttf_y_max - ttf_y_min;

    x_ratio = 1.0f * width / glyph_width;
    y_ratio = 1.0f * height / glyph_height;


    winDC = GetDC(hwndPictureBox);
    xBmi.bmiHeader.biSize = sizeof(BITMAPINFO);
    xBmi.bmiHeader.biSizeImage = width*3*height;
    xBmi.bmiHeader.biBitCount = 24;
    xBmi.bmiHeader.biHeight = height;
    xBmi.bmiHeader.biWidth = width;
    xBmi.bmiHeader.biPlanes = 1;
    xBmi.bmiHeader.biCompression   = BI_RGB;
    hBmp = CreateDIBSection(GetDC(hwndPictureBox), &xBmi, DIB_RGB_COLORS, (void**) &buffer, 0, 0);
    memoryDC = CreateCompatibleDC(GetDC(hwndPictureBox));

	numOfContours = pIglyf->pVTbl->get_Descriptor(pIglyf, g_GlyphIndex)->numberOfContours;

	if (numOfContours < 0) {
		isGlyfComposite = 1;
	} else {
		isGlyfComposite = 0;
	}

	if (isGlyfComposite) {
		cContent = pIglyf->pVTbl->get_CompositeContent(pIglyf, g_GlyphIndex);
		numOfGlyfs = cContent->components->pVTbl->Count(cContent->components);
	} else {
		numOfGlyfs = 1;
	}

	hOldBitmap = (HBITMAP)SelectObject(memoryDC, hBmp);
	FillRect(memoryDC, &rect, (HBRUSH) (COLOR_WINDOW+1));
	hPen = CreatePen(PS_GEOMETRIC ,  10, RGB(0,0, 0)); 
	hPenOld = SelectObject(memoryDC, hPen);

	for (hindex = 0; hindex < numOfGlyfs; hindex++) {
		if (isGlyfComposite) {
			cCompContent = (ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_COMPONENT_CONTENT*) cContent->components->pVTbl->Item(cContent->components, hindex);
			bufGlyfIndex = cCompContent->glyphIndex;
		} else {
			bufGlyfIndex = g_GlyphIndex;
		}
		numOfContours = pIglyf->pVTbl->get_Descriptor(pIglyf, bufGlyfIndex)->numberOfContours;
		points = pIglyf->pVTbl->get_GlyfPoints(pIglyf, bufGlyfIndex);
		sContent = pIglyf->pVTbl->get_SimpleContent(pIglyf, bufGlyfIndex);
		if (points->pVTbl->Count(points) > 0){
			for (jindex = 0; jindex < numOfContours; jindex++){

				endPointBuf = *(int16_t*)sContent->endPtsOfContours->pVTbl->Item(sContent->endPtsOfContours, jindex);
				if (jindex == 0) {
						startPointBuf = 0;
					
					} else {
						startPointBuf = (*(int16_t*)sContent->endPtsOfContours->pVTbl->Item(sContent->endPtsOfContours, jindex - 1)) + 1;
					
					}

				point = (ECO_TRUE_TYPE_FONT_1_GLYPH_POINT*) points->pVTbl->Item(points, startPointBuf);
				if (jindex == 0){
					last = point;
					*pointStart = *point;
					MoveToEx(memoryDC, point->x, point->y, NULL);
				} else {
					last->x += point->x;
					last->y += point->y;
					*pointStart = *last;
					MoveToEx(memoryDC, last->x, last->y, NULL);
				}
			
				for (index = startPointBuf + 1; index <= endPointBuf; index++) {
					point = (ECO_TRUE_TYPE_FONT_1_GLYPH_POINT*) points->pVTbl->Item(points, index);
				
						last->x += point->x;
						last->y += point->y;
						LineTo(memoryDC, last->x, last->y); 
				
				}
				point = (ECO_TRUE_TYPE_FONT_1_GLYPH_POINT*) points->pVTbl->Item(points, startPointBuf);

				LineTo(memoryDC, pointStart->x, pointStart->y);
			}
		}
	}
	
    SelectObject(memoryDC, hPenOld); 
    DeleteObject(hPen); 
    GetWindowRect(hwndPictureBox, &rect);

    /* Переворачиваем изображение по горизонтале */
    SetGraphicsMode(winDC,GM_ADVANCED); 

    xForm.eM11 = (FLOAT) 1.0; 
    xForm.eM12 = (FLOAT) 0.0; 
    xForm.eM21 = (FLOAT) 0.0; 
    xForm.eM22 = (FLOAT) -1.0; 
    xForm.eDx  = (FLOAT) 0.0; 
    xForm.eDy  = (FLOAT) 0.0; 

    SetWorldTransform(winDC, &xForm);

    StretchBlt(winDC, 0, 0, rect.right - rect.left, rect.bottom - rect.top, memoryDC, 0, 0, width, height, SRCCOPY);

    /* Освобождение ресурсов */
    SelectObject(memoryDC, hOldBitmap);
    DeleteDC(memoryDC);
    ReleaseDC(hwndPictureBox, memoryDC);
    ReleaseDC(hwndPictureBox, winDC);
    return TRUE;
}


/*
 *
 * <сводка>
 *   Функция DialogProc
 * </сводка>
 *
 * <описание>
 *   Функция DialogProc
 * </описание>
 *
 */
BOOL CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) { 
    HWND hwndPictureBox;
    HDC hdc;
    PAINTSTRUCT ps;
    CHAR buf[10] = {0};
    int32_t i = 0;
    RECT rc;

    switch (message) { 
        case WM_CREATE:
           CreateWindow(TEXT("STATIC"), TEXT("Glyph"), WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP, 50, 14, 60, 26, hDlg, (HMENU)IDC_STATIC_ORIGINAL, (HINSTANCE)GetWindowLong(hDlg, GWL_HINSTANCE), 0);
           CreateWindow(TEXT("STATIC"), NULL, SS_BITMAP | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 50, 540, 500, 500, hDlg, (HMENU)IDC_BITMAP_ORIGINAL, (HINSTANCE)GetWindowLong(hDlg, GWL_HINSTANCE), 0);
           CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | ES_RIGHT | ES_NUMBER , 100, 10, 70, 24, hDlg, (HMENU)IDC_EDIT_GLYPH_INDEX, (HINSTANCE)GetWindowLong(hDlg, GWL_HINSTANCE), 0);
           CreateWindow(TEXT("BUTTON"), TEXT("Preview"), WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON, 340, 10, 100, 28, hDlg, (HMENU)IDC_BUTTON_PREVIEW, (HINSTANCE)GetWindowLong(hDlg, GWL_HINSTANCE), 0);
           CreateWindow(TEXT("BUTTON"), TEXT("View"), WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON, 180, 10, 100, 28, hDlg, (HMENU)IDC_BUTTON_VIEW, (HINSTANCE)GetWindowLong(hDlg, GWL_HINSTANCE), 0);
           CreateWindow(TEXT("BUTTON"), TEXT("Next"), WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON, 450, 10, 100, 28, hDlg, (HMENU)IDC_BUTTON_NEXT, (HINSTANCE)GetWindowLong(hDlg, GWL_HINSTANCE), 0);

        return TRUE;
        case WM_PAINT:
            hdc = BeginPaint(hDlg, &ps);
            //if (g_pIBMP1 != 0) {
                hwndPictureBox = GetDlgItem(hDlg, IDC_BITMAP_ORIGINAL);
                RenderGlyph(hwndPictureBox, g_pIFontFile);
            //}
            GdiFlush();
            EndPaint(hDlg, &ps);
        break;
        case WM_COMMAND: 
            switch (LOWORD(wParam)) { 
                case IDOK:
                case IDCANCEL:
                    EndDialog(hDlg, wParam); 
                return TRUE; 
                case IDC_BUTTON_PREVIEW:
                    /* хардкод */
                    if (g_GlyphIndex <= 0) {
                        g_GlyphIndex = 100;
                    }
                    else {
                        g_GlyphIndex = g_GlyphIndex--;
                    }
                    _itoa(g_GlyphIndex, buf, 10);
                    SetWindowTextA(GetDlgItem(hDlg, IDC_EDIT_GLYPH_INDEX), buf);
                    GetWindowRect(hDlg,&rc);
                    InvalidateRect(hDlg,&rc,TRUE);
                return TRUE; 
                case IDC_BUTTON_VIEW:
                    if ( GetWindowTextA(GetDlgItem(hDlg, IDC_EDIT_GLYPH_INDEX), buf, 10) > 0) {
                        g_GlyphIndex = atol(buf);
                    }
                    GetWindowRect(hDlg,&rc);
                    InvalidateRect(hDlg,&rc,TRUE);
                return TRUE;
                case IDC_BUTTON_NEXT:
                    /* хардкод */
                    if (g_GlyphIndex >= 100) {
                        g_GlyphIndex = 0;
                    }
                    else {
                        g_GlyphIndex = g_GlyphIndex++;
                    }
                    _itoa(g_GlyphIndex, buf, 10);
                    SetWindowTextA(GetDlgItem(hDlg, IDC_EDIT_GLYPH_INDEX), buf);
                    GetWindowRect(hDlg,&rc);
                    InvalidateRect(hDlg,&rc,TRUE);
                return TRUE;
            }
        break;
        case WM_CLOSE:
            //if (MessageBox(hDlg, TEXT("Close the program?"), TEXT("Close"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
                DestroyWindow(hDlg);
            //}
            return TRUE;

        case WM_DESTROY:
            PostQuitMessage(0);
            return TRUE;
        default:
            return DefWindowProc(hDlg, message, wParam, lParam);
    }
    return FALSE;
}

/*
 *
 * <сводка>
 *   Функция DialogPreview
 * </сводка>
 *
 * <описание>
 *   Функция DialogPreview
 * </описание>
 *
 */
int16_t DialogPreview(IEcoTypographyTTF1FontFile* pIFontFile) {
    int16_t result = -1;
    HWND hDlg;
    WNDCLASS wndClass = {0};
    CREATESTRUCT xCS = {0};
    MSG msg;
    BOOL ret;
    RECT rectScreen;
    int32_t x = 0;
    int32_t y = 0;
    int32_t nCmdShow = 0;

    g_pIFontFile = pIFontFile;

    /* вычисление координат центра экрана */
    GetWindowRect(GetDesktopWindow(), &rectScreen);
    x = rectScreen.right / 2 - 150;
    y = rectScreen.bottom / 2 - 75;

    /* Регистрация класса */
    wndClass.lpfnWndProc = (WNDPROC)DialogProc;
    wndClass.style = CS_HREDRAW|CS_VREDRAW;
    wndClass.hInstance =  GetModuleHandle(0);
    wndClass.lpszClassName = TEXT("Eco TTF Preview");
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;

    RegisterClass(&wndClass);
    //FreeConsole();
    /* Инициализация элементов управления и создание диалогового окна */
    InitCommonControls();
    hDlg = CreateWindow(TEXT("Eco TTF Preview"), TEXT("Eco TTF Preview"), WS_DLGFRAME | WS_POPUP | WS_CAPTION | WS_SYSMENU, x, y, 1024, 800, NULL, NULL,  GetModuleHandle(0), NULL);
    ShowWindow(hDlg, SW_SHOWDEFAULT);

    /* Цикл обработки Windows сообщений */
    while   ((ret = GetMessage(&msg, 0, 0, 0)) != 0) {
        if(ret == -1)
            return -1;

        if  (!IsDialogMessage(hDlg, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return result;
}

