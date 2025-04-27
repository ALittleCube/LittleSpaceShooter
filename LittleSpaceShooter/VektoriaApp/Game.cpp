#include "Game.h"

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)
{
	//---------------------------------
	// Initialisiere die Knotenobjekte:
	//---------------------------------

	// Zuallererst muss die Root mit dem Splash-Screen initialisiert werden, 
	// damit die Engine freigeschaltet wird:
	m_zr.Init(psplash, false, false, true);

	// Hier kommen alle weiteren Initialisierungen hinein: 


	//Bildschirm sieht was
	m_zf.Init(hwnd, procOS);
	m_zv.InitFull(&m_zc);
	//m_zo.InitFull(&m_zi);
	m_zi.Init("textures\\BlackBackground.jpg");
	m_zr.AddFrame(&m_zf);
	m_zf.AddViewport(&m_zv);
	m_zv.AddOverlay(&m_zo);
	m_zr.AddScene(&m_zs);
	//m_zs.AddPlacement(&m_zp);
	//m_zs.AddCamera(&m_zc);

	m_zs.SetPhysicsSpace();

	//Licht/Kamera/Szene
	m_zc.Init(QUARTERPI);
	m_zl.Init(CHVector(-30.0f, -30.0f, -5.0f),CColor(1.0f, 1.0f, 1.0f));
	m_zl2.Init(CHVector(5.0f, 0.0f, -20.0f), CColor(1.0f, 0.5f, 1.0f));
	m_zpCamera.AddCamera(&m_zc);
	m_zs.AddPlacement(&m_zpCamera);
	//m_zs.AddLightParallel(&m_zl); 
	m_zs.AddLightParallel(&m_zl2);
	m_zpCamera.TranslateZ(75.0f);

	//new view
	m_zcCamera1.Init(QUARTERPI);
	m_zcCamera2.Init(QUARTERPI);
	m_zpCamera.AddCamera(&m_zcCamera1);
	m_zpCamera2.AddCamera(&m_zcCamera2);
	m_zs.AddPlacement(&m_zpCamera1);
	m_zs.AddPlacement(&m_zpCamera2);
	//m_zpCamera1.TranslateZ(50.0f);
	m_zpCamera2.TranslateZ(50.0f);

	m_zvPlayer1.InitHalfLeft(&m_zcCamera1);
	m_zvPlayer2.InitHalfRight(&m_zcCamera2);

	m_zf.AddViewport(&m_zvPlayer1);
	m_zf.AddViewport(&m_zvPlayer2);

	m_zvPlayer1.SwitchOff();
	m_zvPlayer2.SwitchOff();



	//Erde
	m_zgSphere.Init(1.0F, &m_zm, 50, 50);
	m_zpErdeMond.AddPlacement(&m_zpSphere);
	m_zpSphere.AddGeo(&m_zgSphere);
	//ErdeMond
	m_zs.AddPlacement(&m_zpErdeMond);
	//mond
	m_zpErdeMond.AddPlacement(&m_zpMond);
	m_zpMond.AddGeo(&m_zgMond);
	m_zgMond.Init(0.3F, &m_zmMond, 50, 50);
	//sonne
	m_zs.AddPlacement(&m_zpSonne);
	m_zpSonne.AddGeo(&m_zgSonne);
	m_zgSonne.Init(5.F, &m_zmSonne, 50, 50);
	//ObligatoryCube
	m_zpSphere.AddPlacement(&m_zpObligatoryCube);
	m_zpObligatoryCube.AddGeo(&m_zgObligatoryCube);
	m_zgObligatoryCube.Init(0.5F, &m_zmObligatoryCube, 50, 50);
	m_zgObligatoryCube.Flip();
	//Todesstern
	m_zpSonne.AddPlacement(&m_zpTodesstern);
	m_zpTodesstern.AddGeo(&m_zgTodesstern);
	m_zgTodesstern.Init(0.8, &m_zmTodesstern, 50, 50);
	//Todesstern1
	m_zpSphere.AddPlacement(&m_zpTodesstern1);
	m_zpTodesstern1.AddGeo(&m_zgTodesstern1);
	m_zgTodesstern1.Init(0.9, &m_zmTodesstern1, 50, 50);
	//Todesstern2
	m_zpSphere.AddPlacement(&m_zpTodesstern2);
	m_zpTodesstern2.AddGeo(&m_zgTodesstern2);
	m_zgTodesstern2.Init(0.7, &m_zmTodesstern1, 50, 50);
	//Todesstern3
	m_zpSphere.AddPlacement(&m_zpTodesstern3);
	m_zpTodesstern3.AddGeo(&m_zgTodesstern3);
	m_zgTodesstern3.Init(0.6, &m_zmTodesstern1, 50, 50);
	//Todesstern4
	m_zpSphere.AddPlacement(&m_zpTodesstern4);
	m_zpTodesstern4.AddGeo(&m_zgTodesstern4);
	m_zgTodesstern4.Init(0.5, &m_zmTodesstern1, 50, 50);
	//Todesstern5
	m_zpErdeMond.AddPlacement(&m_zpTodesstern5);
	m_zpTodesstern5.AddGeo(&m_zgTodesstern5);
	m_zgTodesstern5.Init(0.4, &m_zmTodesstern1, 50, 50);
	//Todesstern6
	m_zpSphere.AddPlacement(&m_zpTodesstern6);
	m_zpTodesstern6.AddGeo(&m_zgTodesstern6);
	m_zgTodesstern6.Init(0.3, &m_zmTodesstern1, 50, 50);
	//Todesstern7
	m_zpSphere.AddPlacement(&m_zpTodesstern7);
	m_zpTodesstern7.AddGeo(&m_zgTodesstern7);
	m_zgTodesstern7.Init(0.5, &m_zmTodesstern1, 50, 50);
	//Todesstern8
	m_zpErdeMond.AddPlacement(&m_zpTodesstern8);
	m_zpTodesstern8.AddGeo(&m_zgTodesstern8);
	m_zgTodesstern8.Init(0.7, &m_zmTodesstern1, 50, 50);
	//Todesstern9
	m_zpSphere.AddPlacement(&m_zpTodesstern9);
	m_zpTodesstern9.AddGeo(&m_zgTodesstern9);
	m_zgTodesstern9.Init(0.8, &m_zmTodesstern1, 50, 50);
	//Todesstern10
	m_zpSphere.AddPlacement(&m_zpTodesstern10);
	m_zpTodesstern10.AddGeo(&m_zgTodesstern10);
	m_zgTodesstern10.Init(1.0, &m_zmTodesstern1, 50, 50);
	//Sky
	m_zs.AddPlacement(&m_zpSky);
	m_zpSky.AddGeo(&m_zgSky);
	m_zgSky.Init(10000.F, &m_zmSky, 50, 50);
	m_zgSky.Flip();
	m_zpSky.SetSky();
	//Tastatur
	m_zf.AddDeviceKeyboard(&m_zdk);
	m_zpCamera.SetTranslationSensitivity(10.f);
	m_zpCamera.SetRotationSensitivity(0.8f);
	m_zpCamera1.SetTranslationSensitivity(15.f);
	m_zpCamera1.SetRotationSensitivity(0.9f);
	//m_zpCamera2.SetTranslationSensitivity(10.f);
	//m_zpCamera2.SetRotationSensitivity(0.8f);
	

	//Cursor

	m_ziRakete.Init("textures\\rocket.gif");
	m_ziHand.Init("textures\\hand.gif");
	m_zoRakete.Init(&m_ziRakete, C2dRect(0.05f, 0.05f), true);
	m_zoHand.Init(&m_ziHand, C2dRect(0.05f, 0.05f), true);
	m_zf.AddDeviceCursor(&m_zdc);
	m_zv.AddOverlay(&m_zoRakete);
	m_zv.AddOverlay(&m_zoHand);
	m_zoRakete.SetLayer(0.1);
	m_zoHand.SetLayer(0.1);



	//auswählen
	m_zr.AddMaterial(&m_zm_Tod_red);
	m_zm_Tod_red.LoadPreset("Blood");
	m_zgsPreselected.Add(&m_zgTodesstern);
	m_zgsPreselected.Add(&m_zgTodesstern1);
	m_zgsPreselected.Add(&m_zgTodesstern2);
	m_zgsPreselected.Add(&m_zgTodesstern3);
	m_zgsPreselected.Add(&m_zgTodesstern4);
	m_zgsPreselected.Add(&m_zgTodesstern5);
	m_zgsPreselected.Add(&m_zgTodesstern6);
	m_zgsPreselected.Add(&m_zgTodesstern7);
	m_zgsPreselected.Add(&m_zgTodesstern8);
	m_zgsPreselected.Add(&m_zgTodesstern9);
	m_zgsPreselected.Add(&m_zgTodesstern10);

	//Verzweiflung
	//m_ziLogo.Init("textures\\");
	//m_ziSingle.Init("textures\\");
	//m_ziTwo.Init("textures\\");
	
	m_zoLogo.InitFull("textures\\Logo_new.jpg");
	m_zv.AddOverlay(&m_zoLogo);
	m_zoLogo.SetLayer(0.9f);
	m_zoSingle.Init("textures\\Single.jpg", C2dRect(0.2, 0.08, 0.42, 0.63),false);
	m_zoLogo.AddOverlay(&m_zoSingle);
	m_zoSingle.SetLayer(0.2f);
	m_zoMulti.Init("textures\\Multi.jpg", C2dRect(0.2, 0.08, 0.42, 0.72), false);
	m_zoLogo.AddOverlay(&m_zoMulti);
	m_zoMulti.SetLayer(0.2f);

	m_zosLogo.Add(&m_zoSingle);
	m_zosLogo.Add(&m_zoMulti);

	m_zoUwin.InitFull("textures\\Uwin.jpg");
	m_zv.AddOverlay(&m_zoUwin);
	m_zoUwin.SetLayer(0.1f);
	m_zoUwin.SwitchOff();

	m_zoUlose.InitFull("textures\\Ulose.jpg");
	m_zv.AddOverlay(&m_zoUlose);
	m_zoUlose.SetLayer(0.1f);
	m_zoUlose.SwitchOff();


	//Schießende Sachen
	m_zpCamera.AddPlacement(&m_zpUfo);
	m_zpUfo.AddGeo(&m_zgUfo);
	m_zgUfo.Init(0.75f, &m_zmUfo, 50, 50);
	m_zmUfo.LoadPreset("Sand");
	m_zpUfo.TranslateZ(-8.0f);
	m_zpUfo.TranslateYDelta(-1.3f);
	//Bullets
	m_zmBullet.LoadPreset("Quicksilver");
	m_zgBullet.Init(0.7f, &m_zmBullet);
	m_zpBulletTemplate.AddGeo(&m_zgBullet);
	m_zpBulletTemplate.SetPhysics(2.0f, 0.1f, 0.f, 200000.1f, true);
	m_zpBulletTemplate.SwitchOff();
	m_zs.AddPlacement(&m_zpBulletTemplate);

	m_zpBullets.RingMake(15, m_zpBulletTemplate);
	m_zs.AddPlacements(m_zpBullets);

	m_zmBulletE.LoadPreset("Concrete");
	m_zgBulletE.Init(0.1f, &m_zmBulletE);
	m_zpBulletTemplateE.AddGeo(&m_zgBulletE);
	m_zpBulletTemplateE.SetPhysics(2.0f, 0.1f, 0.f, 200000.1f, true);
	m_zpBulletTemplateE.SwitchOff();
	m_zs.AddPlacement(&m_zpBulletTemplateE);

	m_zpBulletsEnemy.RingMake(10, m_zpBulletTemplateE);
	m_zs.AddPlacements(m_zpBulletsEnemy);







	//okay, now I'm just sad q.q


	


	//texturen

	m_zm.MakeTextureDiffuse("textures\\earth_image.jpg");
	m_zm.MakeTextureBump("textures\\earth_bump.jpg");
	m_zm.MakeTextureGlow("textures\\earth_glow.jpg");
	m_zm.MakeTextureSpecular("textures\\earth_reflection.jpg");

	m_zmMond.MakeTextureDiffuse("textures\\Moon_Image.jpg");
	m_zmMond.MakeTextureBump("textures\\moon_bump.jpg");

	m_zmSonne.MakeTextureDiffuse("textures\\sonne.jpg");

	m_zmObligatoryCube.MakeTextureDiffuse("textures\\ObligatoryCube.jpg");

	//m_zmTodesstern.MakeTextureDiffuse("textures\\");
	//m_zmTodesstern.MakeTextureBump("textures\\");
	m_zmTodesstern.LoadPreset("MarbleWhite");
	m_zmTodesstern1.LoadPreset("MarbleWhite");

	//m_zmSky.MakeTextureDiffuse("textures\\Weltall.jpeg");
	m_zmSky.LoadPreset("NasaStars");




	//auswählen



	if (m_zdc.ButtonUpLeft()) {
		if (m_zdc.PickGeoPreselected(m_zgsPreselected) != nullptr) {
			if (iCounter_Mat_Tod % 2 == 0) {
				m_zgTodesstern.SetMaterial(&m_zm_Tod_red);
			}
			else {
				m_zgTodesstern.SetMaterial(&m_zmTodesstern1);
			}
			iCounter_Mat_Tod++;
		}
	}



	/*bool bMulti;
	if (m_zdc.ButtonDownLeft()) {
		if (m_zdc.PickOverlayPreselected(m_zosSingle) ) {
			m_zoLogo.SwitchOff();
			m_zoSingle.SwitchOff();
			m_zoMulti.SwitchOff();
			bMulti = false;
		}
		else if (m_zdc.PickOverlayPreselected(m_zosMulti)) {
			m_zoLogo.SwitchOff();
			m_zoSingle.SwitchOff();
			m_zoMulti.SwitchOff();
			bMulti = true;
		}
	}
	*/

	
	for (int i = 0; i < 15; i++) {
		m_zs.AddAudio(&m_zaSchüsse[i]);
		m_zaSchüsse[i].Init("audio//Gun.wav");
	}
	


	//KIEnemy
	m_zgttKIEnemy = m_zfwKIEnemy.LoadGeoTriangleTable("geo//KIEnemy.obj");
	m_zmKIEnemy.LoadPreset("Lemon");
	m_zgttKIEnemy->SetMaterial(&m_zmKIEnemy);
	m_zpKIEnemy.AddGeo(m_zgttKIEnemy);
	m_zpSonne.AddPlacement(&m_zpKIEnemy);
	mCube.LoadPreset("Blood");
	gCube.Init(2.0f, &mCube, 50, 50);
	pCube.AddGeo(&gCube);
	m_zpKIEnemy.AddPlacement(&pCube);
	gCube.Flip();
	mCube.SetChromaKeyingOn();





	//Writings
	m_zwfPlayer.LoadPreset("TannenbergBoldWhite");
	m_zwfEnemy.LoadPreset("TannenbergBoldRed");
	m_zwPlayer.Init(C2dRect(0.1f, 0.05f, 0.05f, 0.1f), 6, &m_zwfPlayer);
	m_zwEnemy.Init(C2dRect(0.1f, 0.05f, 0.9f, 0.1f), 6, &m_zwfEnemy);
	m_zv.AddWriting(&m_zwPlayer);
	m_zv.AddWriting(&m_zwEnemy);
	m_zwPlayer.SetLayer(0.95);
	m_zwEnemy.SetLayer(0.95);
	m_zr.AddMaterial(&m_zwfPlayer);
	m_zr.AddMaterial(&m_zwfEnemy);
	m_zwPlayer.SwitchOff();
	m_zwEnemy.SwitchOff();



	

}







void CGame::Tick(float fTime, float fTimeDelta)
{
	//-------------------------------------------
	// Veränderungen während der Simulationszeit:
	//-------------------------------------------

	float fx, fy;
	m_zdc.GetFractional(fx, fy, true);
	ULDebug("fx: %f, fy: %f", fx, fy);
	if (m_zdc.ButtonPressedLeft()) {
		m_zoRakete.SwitchOff();
		m_zoHand.SwitchOn();
		m_zoHand.SetPos(fx - 0.01f, fy - 0.01f);
	}
	else {
		m_zoHand.SwitchOff();
		m_zoRakete.SwitchOn();
		m_zoRakete.SetPos(fx - 0.01f, fy - 0.01f);
	}


	//KIEnemy
	m_zpKIEnemy.TranslateX(15.f);
	m_zpKIEnemy.RotateYDelta(fTime * 0.6);



	// Hier kommen die Veränderungen pro Renderschritt hinein: 
	m_zpMond.TranslateX(5.0F);
	m_zpErdeMond.TranslateX(30.0F);
	m_zpObligatoryCube.TranslateX(3.0F);
	m_zpTodesstern.TranslateX(8.0F);
	m_zpTodesstern1.TranslateX(7.0F);
	m_zpTodesstern2.TranslateX(10.0F);
	m_zpTodesstern3.TranslateX(6.0F);
	m_zpTodesstern4.TranslateX(20.0F);
	m_zpTodesstern5.TranslateX(8.0F);
	m_zpTodesstern6.TranslateX(15.0F);
	m_zpTodesstern7.TranslateX(11.0F);
	m_zpTodesstern8.TranslateX(16.0F);
	m_zpTodesstern9.TranslateX(13.0F);
	m_zpTodesstern10.TranslateX(18.0F);


	m_zpSphere.RotateY(fTime);
	m_zpSphere.RotateZDelta(0.24f);
	m_zpSphere.TranslateDelta(CHVector(0, 0, -5));
					
	//verwirrendes rumexisteren

	m_zpMond.RotateYDelta(fTime * 0.9);   //Warum machst du keinen kreis, Mond? was geht durch deinen Kopf?

	m_zpErdeMond.RotateYDelta(fTime * 0.4);

	m_zpObligatoryCube.RotateYDelta(fTime * 0.2);

	m_zpTodesstern.RotateYDelta(fTime * 0.6);
	m_zpTodesstern1.RotateYDelta(fTime * 0.2);
	m_zpTodesstern2.RotateYDelta(fTime * 15.0);
	m_zpTodesstern3.RotateYDelta(fTime * 0.3);
	m_zpTodesstern4.RotateYDelta(fTime * 0.6);
	m_zpTodesstern5.RotateYDelta(fTime * 0.22);
	m_zpTodesstern6.RotateYDelta(fTime * 0.1);
	m_zpTodesstern7.RotateYDelta(fTime * 0.95);
	m_zpTodesstern8.RotateYDelta(fTime * 2.0);
	m_zpTodesstern9.RotateYDelta(fTime * 0.5);
	m_zpTodesstern10.RotateYDelta(fTime * 1.3);

	m_zpTodesstern3.RotateZDelta(0.3f); 
	m_zpTodesstern8.RotateZDelta(0.6f);
	m_zpTodesstern6.RotateZDelta(0.44f);
	m_zpTodesstern1.RotateZDelta(0.26f);


	//Pick Single or Multi
	if (m_zdc.ButtonDownLeft()) {
		if (m_zdc.PickOverlayPreselected(m_zosLogo) == &m_zoSingle) 
		{
			m_zoLogo.SwitchOff();
			m_zoSingle.SwitchOff();
			m_zoMulti.SwitchOff();
			m_zwPlayer.SwitchOn();
			m_zwPlayer.PrintF("HP %i", mePunkte);
			bMulti = false;
		}
		else if (m_zdc.PickOverlayPreselected(m_zosLogo) == &m_zoMulti) 
		{
			m_zoLogo.SwitchOff();
			m_zoSingle.SwitchOff();
			m_zoMulti.SwitchOff();
			m_zwPlayer.SwitchOn();
			m_zwEnemy.SwitchOn();
			bMulti = true;
		}
	}



	//Tastatur?
	
	//m_zdk.PlaceWASD(m_zpCamera, fTimeDelta, false);
		

	//Mausie
	m_zpTodesstern.TranslateX(9.9);
	m_zpTodesstern.RotateYDelta(fTime * 0.5);

	
	


	//Split Multi screen
	m_zdk.PlaceWASD(m_zpCamera, fTimeDelta, false);
	if (bMulti == true) {
		m_zv.SwitchOff();
		m_zvPlayer1.SwitchOn();
		m_zvPlayer2.SwitchOn();
		//m_zdk.PlaceWASD(m_zpCamera1, fTimeDelta, false);
	}


	


	//Bullets Kollision
	for (int i = 0; i < 15; i++) {
		if (m_zpBullets.m_applacement[i]->IsOn()) {
			m_avBulletLastPos[i] = m_zpBullets.m_applacement[i]->GetPosGlobal();
		}
	}


	//bullets piupiu
	if (m_zdk.KeyDown(DIK_SPACE)) {
		if (m_zpBullets.RingIsNotFull()) {			
			CPlacement* pzp = m_zpBullets.RingInc();
			pzp->SetMat(m_zpUfo.GetMatGlobal());
			//CHVector vDir = m_zpKIEnemy.GetPosGlobal() - m_zpUfo.GetPosGlobal();
			CHVector vDir = m_zpUfo.GetPosGlobal() - m_zpCamera.GetPosGlobal();
			vDir.Normal();
			//v += CHVector(0.f, 2.f, 0.f, 0.f);
			pzp->SetPhysicsVelocity(vDir * 100.f);

			m_zaSchüsse[m_zpBullets.m_uRingStart].Start();

		}
	}

	CPlacement* pzpOldestBullet = m_zpBullets.RingAskLast();
	if ((pzpOldestBullet)) {
		if (pzpOldestBullet->GetPos().Length() > 1000.f) {
			m_zpBullets.RingDec();
		}
	}


	//EnemyBullets more piupiu
	static float s_fSpawn = 1.f;
	
  	if (m_zr.GetTick()%50 == 0)
		
//		m_zr.IsTime(s_fSpawn)) // */m_zdk.KeyDown(DIK_P)) 
	{
		s_fSpawn += 0.5f;
		if (m_zpBulletsEnemy.RingIsNotFull()) {
			CPlacement* pzb = m_zpBulletsEnemy.RingInc();
			pzb->SetMat(m_zpKIEnemy.GetMatGlobal());
			CHVector v(1.0f, 0.0f, 0.0f, 0.0f);
			if (q == 0) {
				w--;
				if (w == 0) {
					q = 1;
				}
				// if(m_zpUfo.m_uInstances >0 && m_zpTodesstern.m_uInstances)
				v = m_zpUfo.GetPosGlobal() - m_zpKIEnemy.GetPosGlobal();
				v.Normal();
				pzb->SetPhysicsVelocity(v * 35.f);
			} 
			else {
				w++;
				if (w == 5) {
					q = 0;
				}
				v = m_zpSonne.GetPosGlobal() - m_zpKIEnemy.GetPosGlobal();
				v.Normal();
				pzb->SetPhysicsVelocity(v * 35.f);
			}
			
		}
	}
	CPlacement* pzpOldestEnemyBullet = m_zpBulletsEnemy.RingAskLast();
	if ((pzpOldestEnemyBullet)) {
		if (pzpOldestEnemyBullet->GetPos().Length() > 100.f) {
			m_zpBulletsEnemy.RingDec();
		}
	}



	if (mePunkte <= 0) {
		m_zoUlose.SwitchOn();
	}
	else if (mePunkte >= 25) {
		m_zoUwin.SwitchOn();
	}



	
	if (m_zr.GetTick() % 150 == 0) {
		mePunkte--;
		m_zwPlayer.PrintF("HP %i", mePunkte);
	}



	// Traversiere am Schluss den Szenengraf und	rendere:
	m_zr.Tick(fTimeDelta);


	//more bullet collision
	for (int i = 0; i < 15; i++) {
		if (m_zpBullets.m_applacement[i]->IsOn()) {
			CRay rayHitEnemy;
			rayHitEnemy.InitFromTo(m_avBulletLastPos[i], m_zpBullets.m_applacement[i]->GetPosGlobal());
			CHitPoint hitEnemy;
			if (gCube.Intersects(rayHitEnemy, hitEnemy)) {
				mePunkte += 5;
				
			}
		}
		m_zwPlayer.PrintF("HP %i", mePunkte);
	}



}







void CGame::Fini()
{
	//-------------------------------
	// Finalisiere die Knotenobjekte:
	//-------------------------------

	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:

	// Auch die Root sollte finalisiert werden:   
	m_zr.Fini();
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:
	// z.B. mittels: m_zf.ReSize(iNewWidth, iNewHeight);

	m_zf.ReSize(iNewWidth, iNewHeight);
}

float CGame::GetTimeDeltaMin()
{
	return m_zr.GetTimeDeltaMin();
}

float CGame::GetVersion()
{
	return m_zr.GetVersion();
}


