#pragma once
//-----------------------------------------------------------------------
// CGame
// 
// Erklärung : Eine weitestgehend leere Klasse, 
//             sinnfällig in eine Windows-Applikation eingebettet,
//             um ein Spiel bzw. eine 3D-Simulation zu erzeugen
// Autor     : Prof. Dr. Tobias Breiner
// Ort       : Pfungstadt
// Zeit      : seit Aug. 2011 (mit seitdem ständigen Verbesserungs-Updates)
// Copyright : Tobias Breiner  
// Disclaimer: Nutzung auf eigene Gefahr, keine Gewähr, no warranty!
//------------------------------------------------------------------------



#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#endif
#endif


#include "Vektoria\Root.h"

using namespace Vektoria;


class CGame
{
public:
	// Wird vor Begin einmal aufgerufen (Konstruktor):
	CGame(void);																				

	// Wird nach Ende einmal aufgerufen (Destruktor):
	~CGame(void);																				

	// Wird zu Begin einmal aufgerufen:
	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash);	

	// Wird während der Laufzeit bei jedem Bildaufbau aufgerufen:
	void Tick(float fTime, float fTimeDelta);						

	// Wird am Ende einmal aufgerufen:
	void Fini();																				

	// Wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat:
	void WindowReSize(int iNewWidth, int iNewHeight);											

	// Holt das minimale Zeitdelta zur eventuellen Frame-Rate-Beschränkung:
	float GetTimeDeltaMin();																	

	// Holt die Versionsnummer:
	float GetVersion();


	//aaa
	void AddScene(CScene* pscene);
	void AddFrame(CFrame* pframe);
	void Init(HWND hwnd,void(*procOS)(HWND hwnd, unsigned int uWndFlags));
	void InitFull(CCamera* pcamera);
	void Init(float faFovHorizontal = 2.0F,float fNearClipping = 0.1F,float fFarClipping = 3000.0F);
	void InitFull(char* acPath,C2dRect& rect,bool bChromaKeying = false);
	void Init(char* acPath);

	//more aaa
	void AddPlacement(CPlacement* pplacement);
	void AddLightParallel(CLightParallel* pparallellight);
	






private:

	// Die Wurzel des Szenengrafen: 
	CRoot m_zr; 

	// Hier ist Platz für Deine weiteren Vektoriaobjekte:

	//Bildschirm
	CFrame m_zf;
	CViewport m_zv;
	COverlay m_zo;
	CImage m_zi;
	CScene m_zs;
	//CPlacement m_zp;
	//Licht/Kamera/Szene
	CCamera m_zc;
	CLightParallel m_zl;
	CLightParallel m_zl2;
	CPlacement m_zpCamera;
	//Erde
	CPlacement m_zpSphere;
	CGeoSphere m_zgSphere;
	CMaterial m_zm;
	//Mond
	CPlacement m_zpMond;
	CGeoSphere m_zgMond;
	CMaterial m_zmMond;
	//Sonne
	CPlacement m_zpSonne;
	CGeoSphere m_zgSonne;
	CMaterial m_zmSonne;
	//ErdeMond
	CPlacement m_zpErdeMond;
	//ObligatoryCube
	CPlacement m_zpObligatoryCube;
	CGeoCube m_zgObligatoryCube;
	CMaterial m_zmObligatoryCube;
	//Todesstern
	CPlacement m_zpTodesstern;
	CGeoSphereTiled m_zgTodesstern;
	CMaterial m_zmTodesstern;
	//Todesstern1
	CPlacement m_zpTodesstern1;
	CGeoSphereTiled m_zgTodesstern1;
	CMaterial m_zmTodesstern1;
	//Todesstern2
	CPlacement m_zpTodesstern2;
	CGeoSphereTiled m_zgTodesstern2;
	CMaterial m_zmTodesstern2;
	//Todesstern3
	CPlacement m_zpTodesstern3;
	CGeoSphereTiled m_zgTodesstern3;
	CMaterial m_zmTodesstern3;
	//Todesstern4
	CPlacement m_zpTodesstern4;
	CGeoSphereTiled m_zgTodesstern4;
	CMaterial m_zmTodesstern4;
	//Todesstern5
	CPlacement m_zpTodesstern5;
	CGeoSphereTiled m_zgTodesstern5;
	CMaterial m_zmTodesstern5;
	//Todesstern6
	CPlacement m_zpTodesstern6;
	CGeoSphereTiled m_zgTodesstern6;
	CMaterial m_zmTodesstern6;
	//Todesstern7
	CPlacement m_zpTodesstern7;
	CGeoSphereTiled m_zgTodesstern7;
	CMaterial m_zmTodesstern7;
	//Todesstern8
	CPlacement m_zpTodesstern8;
	CGeoSphereTiled m_zgTodesstern8;
	CMaterial m_zmTodesstern8;
	//Todesstern9
	CPlacement m_zpTodesstern9;
	CGeoSphereTiled m_zgTodesstern9;
	CMaterial m_zmTodesstern9;
	//Todesstern10
	CPlacement m_zpTodesstern10;
	CGeoSphereTiled m_zgTodesstern10;
	CMaterial m_zmTodesstern10;

	//Sky
	CPlacement m_zpSky;
	CGeoSphere m_zgSky;
	CMaterial m_zmSky;

	//Tastatur
	CDeviceKeyboard m_zdk;

	//Cursor
	CDeviceCursor m_zdc;
	CImage m_ziRakete;
	CImage m_ziHand;
	COverlay m_zoRakete;
	COverlay m_zoHand;



	//auswählen

	CGeos m_zgsPreselected;
	unsigned int iCounter_Mat_Tod = 0;
	CMaterial m_zm_Tod_red;


	//Verzweiflung
	//CImage m_ziLogo;
	COverlay m_zoLogo;
	//CImage m_ziSingle;
	COverlay m_zoSingle;
	//CImage m_ziTwo;
	COverlay m_zoMulti;
	COverlays m_zosLogo;

	//Schießende Sachen
	CPlacement m_zpUfo;
	CGeoSphere m_zgUfo;
	CMaterial m_zmUfo;


	//Bullets
	CPlacements m_zpBullets;
	CPlacement m_zpBulletTemplate;
	CGeoSphere m_zgBullet;
	CMaterial m_zmBullet;
	CPlacements m_zpBulletsEnemy;
	CPlacement m_zpBulletTemplateE;
	CGeoSphere m_zgBulletE;
	CMaterial m_zmBulletE;
	CHVector m_avBulletLastPos[15];

	//extra viewport
	CCamera m_zcCamera1;
	CCamera m_zcCamera2;
	CPlacement m_zpCamera1;
	CPlacement m_zpCamera2;
	CViewport m_zvPlayer1;
	CViewport m_zvPlayer2;

	//piupiu sound
	CAudio m_zaSchüsse[15];


	//int for eh
	int q = 0;
	int w = 5;
	int mePunkte = 10;
	int enPunkte = 10; 

	//Bullet Collision??



	//KIEnemy
	CFileWavefront m_zfwKIEnemy;
	CGeoTriangleTable* m_zgttKIEnemy = nullptr;
	CPlacement	 m_zpKIEnemy;
	CMaterial m_zmKIEnemy;
	CGeoCube gCube;
	CPlacement pCube;
	CMaterial mCube;


	bool bMulti = false;


	//writings
	CWriting m_zwPlayer;
	CWriting m_zwEnemy;
	CWritingFont m_zwfPlayer;
	CWritingFont m_zwfEnemy;


	//win-lose overlay
	COverlay m_zoUwin;
	COverlay m_zoUlose;
	

	


};


