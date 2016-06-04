#include "Ogre\ExampleApplication.h"
AnimationState* an1macionLaser01;
AnimationState* an1macionLaser02;
AnimationState* an1macionLaser03;
AnimationState* an1macionLaser04;
AnimationState* an1macionLaser05;
AnimationState* an1macionLaser06;
AnimationState* an1macionLaser07;
AnimationState* an1macionLaser08;
float r=1.0;

class FrameListenerClass : public Ogre:: FrameListener 
{
private:
	//Ogre:: SceneNode* _nodoNave01;
	Ogre::Camera* _cam;
	OIS::InputManager* _man;
	OIS::Keyboard*  _key;
	OIS::Mouse* _mouse;
	

public:
	//Constructor
	//FrameListenerClass(Ogre::SceneNode* nodoNave01, Ogre::Camera* cam, RenderWindow* win)
	FrameListenerClass(Ogre::Camera* cam, RenderWindow* win){
		//Configuracion para captura de teclado y mouse
		size_t windowHnd = 0;
		std::stringstream windowHndStr;
		win-> getCustomAttribute("WINDOW",&windowHnd);
		windowHndStr <<windowHnd;

		OIS::ParamList pl;
		pl.insert(std::make_pair(std::string("WINDOW"),windowHndStr.str()));

		//Eventos
		_man = OIS::InputManager::createInputSystem(pl);
		_key =static_cast<OIS::Keyboard*>(_man->createInputObject(OIS::OISKeyboard,false));
		_mouse = static_cast<OIS::Mouse*>(_man->createInputObject(OIS::OISMouse, false));
		
		_cam = cam;	 
		//_nodoNave01 = nodoNave01;	

	}

	//Destructor
	~FrameListenerClass(){
		_man->destroyInputObject(_key);
		_man->destroyInputObject(_mouse);
		OIS::InputManager::destroyInputSystem(_man);
	}

	//Siempre esta escuchando, ejecutando:
	bool frameStarted(const Ogre::FrameEvent &evt){
		_key->capture();
		_mouse->capture();

		float movSpeed = 10.0f; //me controla la velocidad
		Ogre::Vector3 tmov(0,0,0);//movimiento
		Ogre::Vector3 tcam(0,0,0);//camara

		if (_key->isKeyDown(OIS::KC_ESCAPE))
		{
			return false;
		}
		//Camara
		if (_key->isKeyDown(OIS::KC_W))
		{
			tcam += Ogre::Vector3(0,0,-10);
		}
		if (_key->isKeyDown(OIS::KC_S))
		{
			tcam += Ogre::Vector3(0,0,10);
		}
		if (_key->isKeyDown(OIS::KC_A))
		{
			tcam += Ogre::Vector3(-10,0,0);
		}
		if (_key->isKeyDown(OIS::KC_D))
		{
			tcam += Ogre::Vector3(10,0,0);
		}

		//Ogro
		if (_key->isKeyDown(OIS::KC_H))
		{
			tmov += Ogre::Vector3(-10,0,0);
		}
		if (_key->isKeyDown(OIS::KC_K))
		{
			tmov += Ogre::Vector3(10,0,0);
		}
		if (_key->isKeyDown(OIS::KC_U))
		{
			tmov += Ogre::Vector3(0,0,-10);
		}
		if (_key->isKeyDown(OIS::KC_J))
		{
			tmov += Ogre::Vector3(0,0,10);
		}

		//Luz
		if (_key->isKeyDown(OIS::KC_1))
		{
			r -= 0.05;
		}
		if (_key->isKeyDown(OIS::KC_2))
		{
			r += 0.05;
		}
		//LuzPuntual01 -> setDiffuseColour(Ogre::ColourValue(r,1.0,1.0));

		//Camara control
		float rotX = _mouse->getMouseState().X.rel * evt.timeSinceLastFrame * -1;
		float rotY = _mouse->getMouseState().Y.rel * evt.timeSinceLastFrame * -1;
		_cam->yaw(Ogre::Radian(rotX));
		_cam->pitch(Ogre::Radian(rotY));
		_cam-> moveRelative(tcam*movSpeed*evt.timeSinceLastFrame);


		//_nodoNave01 -> translate(tmov*evt.timeSinceLastFrame);

		an1macionLaser01 -> addTime(evt.timeSinceLastFrame);
		an1macionLaser02 -> addTime(evt.timeSinceLastFrame);
		an1macionLaser03 -> addTime(evt.timeSinceLastFrame);
		an1macionLaser04 -> addTime(evt.timeSinceLastFrame);
		an1macionLaser05 -> addTime(evt.timeSinceLastFrame);
		an1macionLaser06 -> addTime(evt.timeSinceLastFrame);
		an1macionLaser07 -> addTime(evt.timeSinceLastFrame);
		an1macionLaser08 -> addTime(evt.timeSinceLastFrame);


		return true;
	}


};
class Example1 : public ExampleApplication
{

public:
	Ogre:: SceneNode* nodeNave01;
	Ogre:: FrameListener* frameListener01;
	Ogre::SceneNode* nodeLaser01;
	Ogre::SceneNode* nodeLaser02;
	Ogre::SceneNode* nodeLaser03;
	Ogre::SceneNode* nodeLaser04;
	Ogre::SceneNode* nodeLaser05;
	Ogre::SceneNode* nodeLaser06;
	Ogre::SceneNode* nodeLaser07;
	Ogre::SceneNode* nodeLaser08;


	//Constructor
	Example1(){
		frameListener01 = NULL;	
	}
	//Destructor
	~Example1(){
		if (frameListener01)
		{
			delete frameListener01;
		}
	}

	//crear un nuevo oido =)
	// por cada objeto... eventualmente sera una arreglo de objetos
	void createFrameListener(){
		//,_cam,win
		frameListener01 = new FrameListenerClass(mCamera, mWindow);
		mRoot-> addFrameListener(frameListener01);
	}


	void createCamera() {

		mCamera = mSceneMgr->createCamera("MyCamera1");
		mCamera->setPosition(0,10,50);
		mCamera->lookAt(0,0,-50);
		mCamera->setNearClipDistance(5);

	}

	void createScene()
	{

		mSceneMgr->setAmbientLight(Ogre::ColourValue(0.1, 0.1, 0.1));
		mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

		 //Luces Pared Izquierda
		 //Esfera(padre)

		 Ogre:: Entity* entEsferaLuz01 = mSceneMgr -> createEntity("entEsferaLuz01","sphere.mesh");
		 Ogre:: Entity* entEsferaLuz02 = mSceneMgr -> createEntity("entEsferaLuz02","sphere.mesh");
		 Ogre:: Entity* entEsferaLuz03 = mSceneMgr -> createEntity("entEsferaLuz03","sphere.mesh");
		 Ogre:: Entity* entEsferaLuz04 = mSceneMgr -> createEntity("entEsferaLuz04","sphere.mesh");
		 Ogre:: Entity* entEsferaLuz05 = mSceneMgr -> createEntity("entEsferaLuz05","sphere.mesh");
		 Ogre:: Entity* entEsferaLuz06 = mSceneMgr -> createEntity("entEsferaLuz06","sphere.mesh");
		 Ogre:: Entity* entEsferaLuz07 = mSceneMgr -> createEntity("entEsferaLuz07","sphere.mesh");
		 Ogre:: Entity* entEsferaLuz08 = mSceneMgr -> createEntity("entEsferaLuz08","sphere.mesh");
		 Ogre:: Entity* entEsferaLuz09 = mSceneMgr -> createEntity("entEsferaLuz09","sphere.mesh");

		 Ogre:: SceneNode* nodeEsferaLuz01 = mSceneMgr -> createSceneNode("nodeEsferaLuz01");
		 Ogre:: SceneNode* nodeEsferaLuz02 = mSceneMgr -> createSceneNode("nodeEsferaLuz02");
		 Ogre:: SceneNode* nodeEsferaLuz03 = mSceneMgr -> createSceneNode("nodeEsferaLuz03");
		 Ogre:: SceneNode* nodeEsferaLuz04 = mSceneMgr -> createSceneNode("nodeEsferaLuz04");
		 Ogre:: SceneNode* nodeEsferaLuz05 = mSceneMgr -> createSceneNode("nodeEsferaLuz05");
		 Ogre:: SceneNode* nodeEsferaLuz06 = mSceneMgr -> createSceneNode("nodeEsferaLuz06");
		 Ogre:: SceneNode* nodeEsferaLuz07 = mSceneMgr -> createSceneNode("nodeEsferaLuz07");
		 Ogre:: SceneNode* nodeEsferaLuz08 = mSceneMgr -> createSceneNode("nodeEsferaLuz08");
		 Ogre:: SceneNode* nodeEsferaLuz09 = mSceneMgr -> createSceneNode("nodeEsferaLuz09");

		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz01);
		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz02);
		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz03);
		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz04);
		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz05);
		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz06);
		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz07);
		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz08);
		 mSceneMgr-> getRootSceneNode() -> addChild(nodeEsferaLuz09);

		 nodeEsferaLuz01 -> attachObject(entEsferaLuz01);
		 nodeEsferaLuz02 -> attachObject(entEsferaLuz02);
		 nodeEsferaLuz03 -> attachObject(entEsferaLuz03);
		 nodeEsferaLuz04 -> attachObject(entEsferaLuz04);
		 nodeEsferaLuz05 -> attachObject(entEsferaLuz05);
		 nodeEsferaLuz06 -> attachObject(entEsferaLuz06);
		 nodeEsferaLuz07 -> attachObject(entEsferaLuz07);
		 nodeEsferaLuz08 -> attachObject(entEsferaLuz08);
		 nodeEsferaLuz09 -> attachObject(entEsferaLuz09);

		 //luces(hijo)
		 Ogre:: Light* LuzPuntual01 = mSceneMgr -> createLight("LuzP01");
		 Ogre:: Light* LuzPuntual02 = mSceneMgr -> createLight("LuzP02");
		 Ogre:: Light* LuzPuntual03 = mSceneMgr -> createLight("LuzP03");
		 Ogre:: Light* LuzPuntual04 = mSceneMgr -> createLight("LuzP04");
		 Ogre:: Light* LuzPuntual05 = mSceneMgr -> createLight("LuzP05");
		 Ogre:: Light* LuzPuntual06 = mSceneMgr -> createLight("LuzP06");
		 Ogre:: Light* LuzPuntual07 = mSceneMgr -> createLight("LuzP07");
		 Ogre:: Light* LuzPuntual08 = mSceneMgr -> createLight("LuzP08");
		 Ogre:: Light* LuzPuntual09 = mSceneMgr -> createLight("LuzP09");

		 Ogre:: SceneNode* nodeLuz01 = mSceneMgr -> createSceneNode("nodeLuz01");
		 Ogre:: SceneNode* nodeLuz02 = mSceneMgr -> createSceneNode("nodeLuz02");		 
		 Ogre:: SceneNode* nodeLuz03 = mSceneMgr -> createSceneNode("nodeLuz03");		 
		 Ogre:: SceneNode* nodeLuz04 = mSceneMgr -> createSceneNode("nodeLuz04");		 
		 Ogre:: SceneNode* nodeLuz05 = mSceneMgr -> createSceneNode("nodeLuz05");		 
		 Ogre:: SceneNode* nodeLuz06 = mSceneMgr -> createSceneNode("nodeLuz06");		 
		 Ogre:: SceneNode* nodeLuz07 = mSceneMgr -> createSceneNode("nodeLuz07");		 
		 Ogre:: SceneNode* nodeLuz08 = mSceneMgr -> createSceneNode("nodeLuz08");		 
		 Ogre:: SceneNode* nodeLuz09 = mSceneMgr -> createSceneNode("nodeLuz09");		 

		 LuzPuntual01 -> setType(Ogre::Light::LT_POINT);
		 LuzPuntual02 -> setType(Ogre::Light::LT_POINT);
		 LuzPuntual03 -> setType(Ogre::Light::LT_POINT);
		 LuzPuntual04 -> setType(Ogre::Light::LT_POINT);
		 LuzPuntual05 -> setType(Ogre::Light::LT_POINT);
		 LuzPuntual06 -> setType(Ogre::Light::LT_POINT);
		 LuzPuntual07 -> setType(Ogre::Light::LT_POINT);
		 LuzPuntual08 -> setType(Ogre::Light::LT_POINT);
		 LuzPuntual09 -> setType(Ogre::Light::LT_POINT);

		 LuzPuntual01 -> setDiffuseColour(0.5,0.5,0.5);
		 LuzPuntual02 -> setDiffuseColour(0.5,0.5,0.5);
		 LuzPuntual03 -> setDiffuseColour(0.5,0.5,0.5);
		 LuzPuntual04 -> setDiffuseColour(0.5,0.5,0.5);
		 LuzPuntual05 -> setDiffuseColour(0.5,0.5,0.5);
		 LuzPuntual06 -> setDiffuseColour(0.5,0.5,0.5);
		 LuzPuntual07 -> setDiffuseColour(0.5,0.5,0.5);
		 LuzPuntual08 -> setDiffuseColour(0.5,0.5,0.5);
		 LuzPuntual09 -> setDiffuseColour(0.5,0.5,0.5);

		 nodeLuz01 -> attachObject(LuzPuntual01);
		 nodeLuz02 -> attachObject(LuzPuntual02);
		 nodeLuz03 -> attachObject(LuzPuntual03);
		 nodeLuz04 -> attachObject(LuzPuntual04);
		 nodeLuz05 -> attachObject(LuzPuntual05);
		 nodeLuz06 -> attachObject(LuzPuntual06);
		 nodeLuz07 -> attachObject(LuzPuntual07);
		 nodeLuz08 -> attachObject(LuzPuntual08);
		 nodeLuz09 -> attachObject(LuzPuntual09);
		 //
		 nodeEsferaLuz01 -> addChild(nodeLuz01);
		 nodeEsferaLuz02 -> addChild(nodeLuz02);
		 nodeEsferaLuz03 -> addChild(nodeLuz03);
		 nodeEsferaLuz04 -> addChild(nodeLuz04);
		 nodeEsferaLuz05 -> addChild(nodeLuz05);
		 nodeEsferaLuz06 -> addChild(nodeLuz06);
		 nodeEsferaLuz07 -> addChild(nodeLuz07);
		 nodeEsferaLuz08 -> addChild(nodeLuz08);
		 nodeEsferaLuz09 -> addChild(nodeLuz09);

		 nodeEsferaLuz01 -> setPosition(0,30,0);
		 nodeEsferaLuz02 -> setPosition(0,30,-150);
		 nodeEsferaLuz03 -> setPosition(0,30,-300);
		 nodeEsferaLuz04 -> setPosition(0,30,-450);
		 nodeEsferaLuz05 -> setPosition(0,30,-600);
		 nodeEsferaLuz06 -> setPosition(0,30,-750);
		 nodeEsferaLuz07 -> setPosition(0,30,-900);
		 nodeEsferaLuz08 -> setPosition(0,30,-1050);
		 nodeEsferaLuz09 -> setPosition(0,30,-1200);

		 nodeEsferaLuz01 -> scale(0.01,0.01,0.01);
		 nodeEsferaLuz02 -> scale(0.01,0.01,0.01);
		 nodeEsferaLuz03 -> scale(0.01,0.01,0.01);
		 nodeEsferaLuz04 -> scale(0.01,0.01,0.01);
		 nodeEsferaLuz05 -> scale(0.01,0.01,0.01);
		 nodeEsferaLuz06 -> scale(0.01,0.01,0.01);
		 nodeEsferaLuz07 -> scale(0.01,0.01,0.01);
		 nodeEsferaLuz08 -> scale(0.01,0.01,0.01);
		 nodeEsferaLuz09 -> scale(0.01,0.01,0.01);

		 //Fin Luz Pared Izquierda

		

		Ogre::Entity* ent01 = mSceneMgr->createEntity("MyEntity1","ejes01.mesh");
		Ogre::SceneNode* node01 = mSceneMgr->createSceneNode("Node01");
		mSceneMgr->getRootSceneNode()->addChild(node01);
		node01->attachObject(ent01);


		//Torreta1 Izquierda
		Ogre::Entity* entCuerpo01 = mSceneMgr -> createEntity("entCuerpo01","usb_cilindro02.mesh");
		Ogre::Entity* entBase01 = mSceneMgr -> createEntity("entBase01","usb_pipe.mesh");
		Ogre::Entity* entCascoSuperior01 = mSceneMgr -> createEntity("entCascoSuperior01","usb_formacurva.mesh");
		Ogre::Entity* entCascoInferior01 = mSceneMgr -> createEntity("entCascoInferior01","usb_formacurva.mesh");
		Ogre::Entity* entCanon01_1 = mSceneMgr -> createEntity("entCanon01_1","usb_laser.mesh");
		Ogre::Entity* entCanon01_2 = mSceneMgr -> createEntity("entCanon01_2","usb_laser.mesh");
		Ogre::Entity* entPuntaCanon01_1 = mSceneMgr -> createEntity("entPuntaCanon01_1","usb_cubomod01.mesh");
		Ogre::Entity* entPuntaCanon01_2 = mSceneMgr -> createEntity("entPuntaCanon01_2","usb_cubomod01.mesh");

		Ogre::SceneNode* nodeTorreta01 = mSceneMgr->createSceneNode("nodeTorreta01");
		Ogre::SceneNode* nodeCuerpo01 = mSceneMgr->createSceneNode("nodeCuerpo01");
		Ogre::SceneNode* nodeCascoSuperior01 = mSceneMgr->createSceneNode("nodeCascoSuperior01");
		Ogre::SceneNode* nondeCascoInferior01 = mSceneMgr->createSceneNode("nondeCascoInferior01");
		Ogre::SceneNode* nodeCanon01_1 = mSceneMgr->createSceneNode("nodeCanon01_1");
		Ogre::SceneNode* nodeCanon01_2 = mSceneMgr->createSceneNode("nodeCanon01_2");
		Ogre::SceneNode* nodePuntaCanon01_1 = mSceneMgr->createSceneNode("nodePuntaCanon01_1");
		Ogre::SceneNode* nodePuntaCanon01_2 = mSceneMgr->createSceneNode("nodePuntaCanon01_2");
		Ogre::SceneNode* nodeBase01 = mSceneMgr->createSceneNode("nodeBase01");
		Ogre::SceneNode* nodeCanon01 = mSceneMgr->createSceneNode("nodoCanon01");
		Ogre::SceneNode* nodeCasco01 = mSceneMgr->createSceneNode("nodoCasco01");


		mSceneMgr->getRootSceneNode()->addChild(nodeTorreta01); //Nodo Padre de la Torreta 01
		nodeCuerpo01->attachObject(entCuerpo01);
		nodeCascoSuperior01->attachObject(entCascoSuperior01);
		nondeCascoInferior01->attachObject(entCascoInferior01);
		nodeCanon01_1->attachObject(entCanon01_1);
		nodeCanon01_2->attachObject(entCanon01_2);
		nodePuntaCanon01_1->attachObject(entPuntaCanon01_1);
		nodePuntaCanon01_2->attachObject(entPuntaCanon01_2);		
		nodeBase01->attachObject(entBase01);

		nodeTorreta01 -> addChild(nodeBase01);
		nodeTorreta01 -> addChild(nodeCuerpo01);
		nodeTorreta01 -> addChild(nodeCasco01);
		nodeCasco01 -> addChild(nodeCascoSuperior01);
		nodeCasco01 -> addChild(nondeCascoInferior01);
		nodeCasco01 -> addChild(nodeCanon01);
		nodeCanon01 -> addChild(nodeCanon01_1);
		nodeCanon01 -> addChild(nodeCanon01_2);
		nodeCanon01 -> addChild(nodePuntaCanon01_1);
		nodeCanon01 -> addChild(nodePuntaCanon01_2);

		nodeTorreta01 -> setPosition(-22,-9.5,-227.5);
		nodeTorreta01 -> yaw(Ogre::Degree(5.0f));
		nodeBase01->scale(0.5,0.5,0.5);
		nodeCuerpo01 -> translate(0,3.5,0);
		nodeCuerpo01 -> scale(0.95,0.6,0.95);
		nodeCasco01 -> translate(0,5.8,0);
		nodeCascoSuperior01->scale(0.4,0.5,0.4);
		nondeCascoInferior01->scale(0.4,0.3,0.4);
		nondeCascoInferior01->pitch(Ogre::Degree(180.0f));
		nodeCanon01_1->translate(0.2,0,4);
		nodeCanon01_2->translate(-0.2,0,4);
		nodeCanon01_1->pitch(Ogre::Degree(270.0f));
		nodeCanon01_2->pitch(Ogre::Degree(270.0f));
		nodeCanon01_1->scale(0.2,0.2,0.2);
		nodeCanon01_2->scale(0.2,0.2,0.2);




		nodePuntaCanon01_1->scale(0.03,0.2,0.03);
		nodePuntaCanon01_2->scale(0.03,0.2,0.03);
		nodePuntaCanon01_1->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_2->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_1 -> translate(0.2,0,7);
		nodePuntaCanon01_2 -> translate(-0.2,0,7);
		/*
		nodePuntaCanon01_1->scale(0.05,0.8,0.05);
		nodePuntaCanon01_2->scale(0.05,0.8,0.05);
		nodePuntaCanon01_1->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_2->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_1 -> translate(0.2,0,6.5);
		nodePuntaCanon01_2 -> translate(-0.2,0,6.5);
		*/
		Ogre::Entity* entLaser01 = mSceneMgr -> createEntity("entLase01","usb_laser.mesh");
		nodeLaser01 = mSceneMgr->createSceneNode("nodoLaser01");
		nodeLaser01 -> attachObject(entLaser01);
		nodeCanon01 -> addChild(nodeLaser01);
		nodeLaser01->translate(0.2,0,6);
		nodeLaser01->pitch(Ogre::Degree(90.0f));
		nodeLaser01->scale(0.1,0.1,0.1);

		Ogre::Entity* entLaser02 = mSceneMgr -> createEntity("entLaser02","usb_laser.mesh");
		nodeLaser02 = mSceneMgr->createSceneNode("nodoLaser02");
		nodeLaser02 -> attachObject(entLaser02);
		nodeCanon01 -> addChild(nodeLaser02);
		nodeLaser02->translate(-0.2,0,8);
		nodeLaser02->pitch(Ogre::Degree(90.0f));
		nodeLaser02->scale(0,0,0);
		 //Crear Animacion de laTorreta 1
		//Laser01		 
		 float duration = 1;		 
		 Ogre::Animation* animationTorreta01 = mSceneMgr -> createAnimation("animTorreta01",duration);
		 animationTorreta01 -> setInterpolationMode(Animation::IM_SPLINE);
		 Ogre::NodeAnimationTrack* trackLaser01 = animationTorreta01->createNodeTrack(0,nodeLaser01);
		 //Ogre::NodeAnimationTrack* trackLaser02 = animationTorreta01->createNodeTrack(0,nodeLaser02);
		 Ogre::TransformKeyFrame* key;
		 key = trackLaser01 -> createNodeKeyFrame(0.0);
		 key -> setTranslate(Vector3(0.2,0,8));
		 key -> setScale(Vector3(0.1,0.1,0.1));
		 key -> setRotation(Quaternion(1,1,0,0));		
		 key = trackLaser01 -> createNodeKeyFrame(0.5);
		 key -> setTranslate(Vector3(0.2,0,100));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 key = trackLaser01 -> createNodeKeyFrame(1.0);
		 key -> setTranslate(Vector3(0.2,0,227));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 an1macionLaser01 = mSceneMgr -> createAnimationState("animTorreta01");
		 an1macionLaser01 -> setEnabled(true);
		 an1macionLaser01 -> setLoop(true);
		//Laser02		 		 
		 Ogre::Animation* animationTorreta01_1 = mSceneMgr -> createAnimation("animTorreta01_1",duration);
		 animationTorreta01_1 -> setInterpolationMode(Animation::IM_SPLINE);
		 Ogre::NodeAnimationTrack* trackLaser02 = animationTorreta01_1->createNodeTrack(0,nodeLaser02);
		 key = trackLaser02 -> createNodeKeyFrame(0);
		 key -> setTranslate(Vector3(-0.2,0,8));
		 key -> setScale(Vector3(0.1,0.1,0.1));
		 key -> setRotation(Quaternion(1,1,0,0));		
		 key = trackLaser02-> createNodeKeyFrame(0.5);
		 key -> setTranslate(Vector3(-0.2,0,100));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 key = trackLaser02 -> createNodeKeyFrame(1);
		 key -> setTranslate(Vector3(-0.2,0,227));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 an1macionLaser02 = mSceneMgr -> createAnimationState("animTorreta01_1");
		 an1macionLaser02 -> setEnabled(true);
		 an1macionLaser02 -> setLoop(true);
		 


		//Torreta2 Izquierda
		Ogre::Entity* entCuerpo02 = mSceneMgr -> createEntity("entCuerpo02","usb_cilindro02.mesh");
		Ogre::Entity* entBase02 = mSceneMgr -> createEntity("entBase02","usb_pipe.mesh");
		Ogre::Entity* entCascoSuperior02 = mSceneMgr -> createEntity("entCascoSuperior02","usb_formacurva.mesh");
		Ogre::Entity* entCascoInferior02 = mSceneMgr -> createEntity("entCascoInferior02","usb_formacurva.mesh");
		Ogre::Entity* entCanon02_1 = mSceneMgr -> createEntity("entCanon02_1","usb_laser.mesh");
		Ogre::Entity* entCanon02_2 = mSceneMgr -> createEntity("entCanon02_2","usb_laser.mesh");
		Ogre::Entity* entPuntaCanon02_1 = mSceneMgr -> createEntity("entPuntaCanon02_1","usb_cubomod01.mesh");
		Ogre::Entity* entPuntaCanon02_2 = mSceneMgr -> createEntity("entPuntaCanon02_2","usb_cubomod01.mesh");


		Ogre::SceneNode* nodeTorreta02 = mSceneMgr->createSceneNode("nodeTorreta02");
		Ogre::SceneNode* nodeCuerpo02 = mSceneMgr->createSceneNode("nodeCuerpo02");
		Ogre::SceneNode* nodeCascoSuperior02 = mSceneMgr->createSceneNode("nodeCascoSuperior02");
		Ogre::SceneNode* nondeCascoInferior02 = mSceneMgr->createSceneNode("nondeCascoInferior02");
		Ogre::SceneNode* nodeCanon02_1 = mSceneMgr->createSceneNode("nodeCanon02_1");
		Ogre::SceneNode* nodeCanon02_2 = mSceneMgr->createSceneNode("nodeCanon02_2");
		Ogre::SceneNode* nodePuntaCanon02_1 = mSceneMgr->createSceneNode("nodePuntaCanon02_1");
		Ogre::SceneNode* nodePuntaCanon02_2 = mSceneMgr->createSceneNode("nodePuntaCanon02_2");
		Ogre::SceneNode* nodeBase02 = mSceneMgr->createSceneNode("nodeBase02");
		Ogre::SceneNode* nodeCanon02 = mSceneMgr->createSceneNode("nodoCanon02");
		Ogre::SceneNode* nodeCasco02 = mSceneMgr->createSceneNode("nodoCasco02");


		mSceneMgr->getRootSceneNode()->addChild(nodeTorreta02); //Nodo Padre de la Torreta 02
		nodeCuerpo02->attachObject(entCuerpo02);
		nodeCascoSuperior02->attachObject(entCascoSuperior02);
		nondeCascoInferior02->attachObject(entCascoInferior02);
		nodeCanon02_1->attachObject(entCanon02_1);
		nodeCanon02_2->attachObject(entCanon02_2);
		nodePuntaCanon02_1->attachObject(entPuntaCanon02_1);
		nodePuntaCanon02_2->attachObject(entPuntaCanon02_2);		
		nodeBase02->attachObject(entBase02);

		nodeTorreta02 -> addChild(nodeBase02);
		nodeTorreta02 -> addChild(nodeCuerpo02);
		nodeTorreta02 -> addChild(nodeCasco02);
		nodeCasco02 -> addChild(nodeCascoSuperior02);
		nodeCasco02 -> addChild(nondeCascoInferior02);
		nodeCasco02 -> addChild(nodeCanon02);
		nodeCanon02 -> addChild(nodeCanon02_1);
		nodeCanon02 -> addChild(nodeCanon02_2);
		nodeCanon02 -> addChild(nodePuntaCanon02_1);
		nodeCanon02 -> addChild(nodePuntaCanon02_2);

		nodeTorreta02 -> setPosition(-22.5,-9.5,-637.5);
		nodeTorreta02 -> yaw(Ogre::Degree(3.0f));
		nodeBase02->scale(0.5,0.5,0.5);
		nodeCuerpo02 -> translate(0,3.5,0);
		nodeCuerpo02 -> scale(0.95,0.6,0.95);
		nodeCasco02 -> translate(0,5.8,0);
		nodeCascoSuperior02->scale(0.4,0.5,0.4);
		nondeCascoInferior02->scale(0.4,0.3,0.4);
		nondeCascoInferior02->pitch(Ogre::Degree(180.0f));
		nodeCanon02_1->translate(0.2,0,4);
		nodeCanon02_2->translate(-0.2,0,4);
		nodeCanon02_1->pitch(Ogre::Degree(270.0f));
		nodeCanon02_2->pitch(Ogre::Degree(270.0f));
		nodeCanon02_1->scale(0.2,0.2,0.2);
		nodeCanon02_2->scale(0.2,0.2,0.2);

		nodePuntaCanon02_1->scale(0.03,0.2,0.03);
		nodePuntaCanon02_2->scale(0.03,0.2,0.03);
		nodePuntaCanon02_1->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon02_2->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon02_1 -> translate(0.2,0,7);
		nodePuntaCanon02_2 -> translate(-0.2,0,7);
		/*
		nodePuntaCanon01_1->scale(0.05,0.8,0.05);
		nodePuntaCanon01_2->scale(0.05,0.8,0.05);
		nodePuntaCanon01_1->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_2->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_1 -> translate(0.2,0,6.5);
		nodePuntaCanon01_2 -> translate(-0.2,0,6.5);
		*/

		Ogre::Entity* entLaser03 = mSceneMgr -> createEntity("entLaser03","usb_laser.mesh");
		nodeLaser03 = mSceneMgr->createSceneNode("nodoLaser03");
		nodeLaser03 -> attachObject(entLaser03);
		nodeCanon02 -> addChild(nodeLaser03);
		nodeLaser03->translate(0.2,0,6);
		nodeLaser03->pitch(Ogre::Degree(90.0f));
		nodeLaser03->scale(0.1,0.1,0.1);

		Ogre::Entity* entLaser04 = mSceneMgr -> createEntity("entLaser04","usb_laser.mesh");
		nodeLaser04 = mSceneMgr->createSceneNode("nodoLaser04");
		nodeLaser04 -> attachObject(entLaser04);
		nodeCanon02 -> addChild(nodeLaser04);
		nodeLaser02->translate(-0.2,0,8);
		nodeLaser02->pitch(Ogre::Degree(90.0f));
		nodeLaser02->scale(0,0,0);
		 //Crear Animacion de laTorreta 2
		//Laser01		 
		 float duration2 = 2;		 
		 Ogre::Animation* animationTorreta02 = mSceneMgr -> createAnimation("animTorreta02",duration2);
		 animationTorreta02 -> setInterpolationMode(Animation::IM_SPLINE);
		 Ogre::NodeAnimationTrack* trackLaser03 = animationTorreta02->createNodeTrack(0,nodeLaser03);
		 key = trackLaser03 -> createNodeKeyFrame(0.0);
		 key -> setTranslate(Vector3(0.2,0,8));
		 key -> setScale(Vector3(0.1,0.1,0.1));
		 key -> setRotation(Quaternion(1,1,0,0));		
		 key = trackLaser03 -> createNodeKeyFrame(1);
		 key -> setTranslate(Vector3(0.2,0,315));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 key = trackLaser03 -> createNodeKeyFrame(2);
		 key -> setTranslate(Vector3(0.2,0,638));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 an1macionLaser03 = mSceneMgr -> createAnimationState("animTorreta02");
		 an1macionLaser03 -> setEnabled(true);
		 an1macionLaser03 -> setLoop(true);
		//Laser02		 		 
		 Ogre::Animation* animationTorreta02_1 = mSceneMgr -> createAnimation("animTorreta02_1",duration2);
		 animationTorreta02_1 -> setInterpolationMode(Animation::IM_SPLINE);
		 Ogre::NodeAnimationTrack* trackLaser04 = animationTorreta02_1->createNodeTrack(0,nodeLaser04);
		 key = trackLaser04 -> createNodeKeyFrame(0);
		 key -> setTranslate(Vector3(-0.2,0,8));
		 key -> setScale(Vector3(0.1,0.1,0.1));
		 key -> setRotation(Quaternion(1,1,0,0));		
		 key = trackLaser04-> createNodeKeyFrame(1);
		 key -> setTranslate(Vector3(-0.2,0,315));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 key = trackLaser04 -> createNodeKeyFrame(2);
		 key -> setTranslate(Vector3(-0.2,0,638));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 an1macionLaser04 = mSceneMgr -> createAnimationState("animTorreta02_1");
		 an1macionLaser04 -> setEnabled(true);
		 an1macionLaser04 -> setLoop(true);


		//Torreta1 Derecha
		Ogre::Entity* entCuerpo03 = mSceneMgr -> createEntity("entCuerpo03","usb_cilindro02.mesh");
		Ogre::Entity* entBase03 = mSceneMgr -> createEntity("entBase03","usb_pipe.mesh");
		Ogre::Entity* entCascoSuperior03 = mSceneMgr -> createEntity("entCascoSuperior03","usb_formacurva.mesh");
		Ogre::Entity* entCascoInferior03 = mSceneMgr -> createEntity("entCascoInferior03","usb_formacurva.mesh");
		Ogre::Entity* entCanon03_1 = mSceneMgr -> createEntity("entCanon03_1","usb_laser.mesh");
		Ogre::Entity* entCanon03_2 = mSceneMgr -> createEntity("entCanon03_2","usb_laser.mesh");
		Ogre::Entity* entPuntaCanon03_1 = mSceneMgr -> createEntity("entPuntaCanon03_1","usb_cubomod01.mesh");
		Ogre::Entity* entPuntaCanon03_2 = mSceneMgr -> createEntity("entPuntaCanon03_2","usb_cubomod01.mesh");


		Ogre::SceneNode* nodeTorreta03 = mSceneMgr->createSceneNode("nodeTorreta03");
		Ogre::SceneNode* nodeCuerpo03 = mSceneMgr->createSceneNode("nodeCuerpo03");
		Ogre::SceneNode* nodeCascoSuperior03 = mSceneMgr->createSceneNode("nodeCascoSuperior03");
		Ogre::SceneNode* nondeCascoInferior03 = mSceneMgr->createSceneNode("nondeCascoInferior03");
		Ogre::SceneNode* nodeCanon03_1 = mSceneMgr->createSceneNode("nodeCanon03_1");
		Ogre::SceneNode* nodeCanon03_2 = mSceneMgr->createSceneNode("nodeCanon03_2");
		Ogre::SceneNode* nodePuntaCanon03_1 = mSceneMgr->createSceneNode("nodePuntaCanon03_1");
		Ogre::SceneNode* nodePuntaCanon03_2 = mSceneMgr->createSceneNode("nodePuntaCanon03_2");
		Ogre::SceneNode* nodeBase03 = mSceneMgr->createSceneNode("nodeBase03");
		Ogre::SceneNode* nodeCanon03 = mSceneMgr->createSceneNode("nodoCanon03");
		Ogre::SceneNode* nodeCasco03 = mSceneMgr->createSceneNode("nodoCasco03");




		mSceneMgr->getRootSceneNode()->addChild(nodeTorreta03); //Nodo Padre de la Torreta 02
		nodeCuerpo03->attachObject(entCuerpo03);
		nodeCascoSuperior03->attachObject(entCascoSuperior03);
		nondeCascoInferior03->attachObject(entCascoInferior03);
		nodeCanon03_1->attachObject(entCanon03_1);
		nodeCanon03_2->attachObject(entCanon03_2);
		nodePuntaCanon03_1->attachObject(entPuntaCanon03_1);
		nodePuntaCanon03_2->attachObject(entPuntaCanon03_2);		
		nodeBase03->attachObject(entBase03);

		nodeTorreta03 -> addChild(nodeBase03);
		nodeTorreta03 -> addChild(nodeCuerpo03);
		nodeTorreta03 -> addChild(nodeCasco03);
		nodeCasco03 -> addChild(nodeCascoSuperior03);
		nodeCasco03 -> addChild(nondeCascoInferior03);
		nodeCasco03 -> addChild(nodeCanon03);
		nodeCanon03 -> addChild(nodeCanon03_1);
		nodeCanon03 -> addChild(nodeCanon03_2);
		nodeCanon03 -> addChild(nodePuntaCanon03_1);
		nodeCanon03 -> addChild(nodePuntaCanon03_2);

		nodeTorreta03 -> setPosition(22,-9.5,-408);
		nodeTorreta03 -> yaw(Ogre::Degree(-4.0f));
		nodeBase03->scale(0.5,0.5,0.5);
		nodeCuerpo03 -> translate(0,3.5,0);
		nodeCuerpo03 -> scale(0.95,0.6,0.95);
		nodeCasco03 -> translate(0,5.8,0);
		nodeCascoSuperior03->scale(0.4,0.5,0.4);
		nondeCascoInferior03->scale(0.4,0.3,0.4);
		nondeCascoInferior03->pitch(Ogre::Degree(180.0f));
		nodeCanon03_1->translate(0.2,0,4);
		nodeCanon03_2->translate(-0.2,0,4);
		nodeCanon03_1->pitch(Ogre::Degree(270.0f));
		nodeCanon03_2->pitch(Ogre::Degree(270.0f));
		nodeCanon03_1->scale(0.2,0.2,0.2);
		nodeCanon03_2->scale(0.2,0.2,0.2);

		nodePuntaCanon03_1->scale(0.03,0.2,0.03);
		nodePuntaCanon03_2->scale(0.03,0.2,0.03);
		nodePuntaCanon03_1->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon03_2->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon03_1 -> translate(0.2,0,7);
		nodePuntaCanon03_2 -> translate(-0.2,0,7);
		/*
		nodePuntaCanon01_1->scale(0.05,0.8,0.05);
		nodePuntaCanon01_2->scale(0.05,0.8,0.05);
		nodePuntaCanon01_1->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_2->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_1 -> translate(0.2,0,6.5);
		nodePuntaCanon01_2 -> translate(-0.2,0,6.5);
		*/

		//Crear Animacion de laTorreta 3
		Ogre::Entity* entLaser05 = mSceneMgr -> createEntity("entLaser05","usb_laser.mesh");
		nodeLaser05 = mSceneMgr->createSceneNode("nodoLaser05");
		nodeLaser05 -> attachObject(entLaser05);
		nodeCanon03 -> addChild(nodeLaser05);
		nodeLaser05->translate(0.2,0,6);
		nodeLaser05->pitch(Ogre::Degree(90.0f));
		nodeLaser05->scale(0.1,0.1,0.1);

		Ogre::Entity* entLaser06 = mSceneMgr -> createEntity("entLaser06","usb_laser.mesh");
		nodeLaser06 = mSceneMgr->createSceneNode("nodoLaser06");
		nodeLaser06 -> attachObject(entLaser06);
		nodeCanon03 -> addChild(nodeLaser06);
		nodeLaser06->translate(-0.2,0,8);
		nodeLaser06->pitch(Ogre::Degree(90.0f));
		nodeLaser06->scale(0,0,0);
		 
		//Laser01		 
		 float duration3 = 1.5;		 
		 Ogre::Animation* animationTorreta03 = mSceneMgr -> createAnimation("animTorreta03",duration3);
		 animationTorreta03 -> setInterpolationMode(Animation::IM_SPLINE);
		 Ogre::NodeAnimationTrack* trackLaser05 = animationTorreta03->createNodeTrack(0,nodeLaser05);
		 key = trackLaser05 -> createNodeKeyFrame(0.0);
		 key -> setTranslate(Vector3(0.2,0,8));
		 key -> setScale(Vector3(0.1,0.1,0.1));
		 key -> setRotation(Quaternion(1,1,0,0));		
		 key = trackLaser05 -> createNodeKeyFrame(0.75);
		 key -> setTranslate(Vector3(0.2,0,204));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 key = trackLaser05 -> createNodeKeyFrame(1.5);
		 key -> setTranslate(Vector3(0.2,0,408));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 an1macionLaser05 = mSceneMgr -> createAnimationState("animTorreta03");
		 an1macionLaser05 -> setEnabled(true);
		 an1macionLaser05 -> setLoop(true);
		//Laser02		 		 
		 Ogre::Animation* animationTorreta03_1 = mSceneMgr -> createAnimation("animTorreta03_1",duration3);
		 animationTorreta03_1 -> setInterpolationMode(Animation::IM_SPLINE);
		 Ogre::NodeAnimationTrack* trackLaser06 = animationTorreta03_1->createNodeTrack(0,nodeLaser06);
		 key = trackLaser06 -> createNodeKeyFrame(0);
		 key -> setTranslate(Vector3(-0.2,0,8));
		 key -> setScale(Vector3(0.1,0.1,0.1));
		 key -> setRotation(Quaternion(1,1,0,0));		
		 key = trackLaser06-> createNodeKeyFrame(0.75);
		 key -> setTranslate(Vector3(-0.2,0,204));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 key = trackLaser06 -> createNodeKeyFrame(1.5);
		 key -> setTranslate(Vector3(-0.2,0,408));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 an1macionLaser06 = mSceneMgr -> createAnimationState("animTorreta03_1");
		 an1macionLaser06 -> setEnabled(true);
		 an1macionLaser06 -> setLoop(true);

		//Torreta2 Derecha
		Ogre::Entity* entCuerpo04 = mSceneMgr -> createEntity("entCuerpo04","usb_cilindro02.mesh");
		Ogre::Entity* entBase04 = mSceneMgr -> createEntity("entBase04","usb_pipe.mesh");
		Ogre::Entity* entCascoSuperior04 = mSceneMgr -> createEntity("entCascoSuperior04","usb_formacurva.mesh");
		Ogre::Entity* entCascoInferior04 = mSceneMgr -> createEntity("entCascoInferior04","usb_formacurva.mesh");
		Ogre::Entity* entCanon04_1 = mSceneMgr -> createEntity("entCanon04_1","usb_laser.mesh");
		Ogre::Entity* entCanon04_2 = mSceneMgr -> createEntity("entCanon04_2","usb_laser.mesh");
		Ogre::Entity* entPuntaCanon04_1 = mSceneMgr -> createEntity("entPuntaCanon04_1","usb_cubomod01.mesh");
		Ogre::Entity* entPuntaCanon04_2 = mSceneMgr -> createEntity("entPuntaCanon04_2","usb_cubomod01.mesh");


		Ogre::SceneNode* nodeTorreta04 = mSceneMgr->createSceneNode("nodeTorreta04");
		Ogre::SceneNode* nodeCuerpo04 = mSceneMgr->createSceneNode("nodeCuerpo04");
		Ogre::SceneNode* nodeCascoSuperior04 = mSceneMgr->createSceneNode("nodeCascoSuperior04");
		Ogre::SceneNode* nondeCascoInferior04 = mSceneMgr->createSceneNode("nondeCascoInferior04");
		Ogre::SceneNode* nodeCanon04_1 = mSceneMgr->createSceneNode("nodeCanon04_1");
		Ogre::SceneNode* nodeCanon04_2 = mSceneMgr->createSceneNode("nodeCanon04_2");
		Ogre::SceneNode* nodePuntaCanon04_1 = mSceneMgr->createSceneNode("nodePuntaCanon04_1");
		Ogre::SceneNode* nodePuntaCanon04_2 = mSceneMgr->createSceneNode("nodePuntaCanon04_2");
		Ogre::SceneNode* nodeBase04 = mSceneMgr->createSceneNode("nodeBase04");
		Ogre::SceneNode* nodeCanon04 = mSceneMgr->createSceneNode("nodoCanon04");
		Ogre::SceneNode* nodeCasco04 = mSceneMgr->createSceneNode("nodoCasco04");




		mSceneMgr->getRootSceneNode()->addChild(nodeTorreta04); //Nodo Padre de la Torreta 02
		nodeCuerpo04->attachObject(entCuerpo04);
		nodeCascoSuperior04->attachObject(entCascoSuperior04);
		nondeCascoInferior04->attachObject(entCascoInferior04);
		nodeCanon04_1->attachObject(entCanon04_1);
		nodeCanon04_2->attachObject(entCanon04_2);
		nodePuntaCanon04_1->attachObject(entPuntaCanon04_1);
		nodePuntaCanon04_2->attachObject(entPuntaCanon04_2);		
		nodeBase04->attachObject(entBase04);

		nodeTorreta04 -> addChild(nodeBase04);
		nodeTorreta04 -> addChild(nodeCuerpo04);
		nodeTorreta04 -> addChild(nodeCasco04);
		nodeCasco04 -> addChild(nodeCascoSuperior04);
		nodeCasco04 -> addChild(nondeCascoInferior04);
		nodeCasco04 -> addChild(nodeCanon04);
		nodeCanon04 -> addChild(nodeCanon04_1);
		nodeCanon04 -> addChild(nodeCanon04_2);
		nodeCanon04 -> addChild(nodePuntaCanon04_1);
		nodeCanon04 -> addChild(nodePuntaCanon04_2);

		nodeTorreta04 -> setPosition(21.5,-9.5,-883.5);
		nodeTorreta04 -> yaw(Ogre::Degree(-2.0f));
		nodeBase04->scale(0.5,0.5,0.5);
		nodeCuerpo04 -> translate(0,3.5,0);
		nodeCuerpo04 -> scale(0.95,0.6,0.95);
		nodeCasco04 -> translate(0,5.8,0);
		nodeCascoSuperior04->scale(0.4,0.5,0.4);
		nondeCascoInferior04->scale(0.4,0.3,0.4);
		nondeCascoInferior04->pitch(Ogre::Degree(180.0f));
		nodeCanon04_1->translate(0.2,0,4);
		nodeCanon04_2->translate(-0.2,0,4);
		nodeCanon04_1->pitch(Ogre::Degree(270.0f));
		nodeCanon04_2->pitch(Ogre::Degree(270.0f));
		nodeCanon04_1->scale(0.2,0.2,0.2);
		nodeCanon04_2->scale(0.2,0.2,0.2);

		nodePuntaCanon04_1->scale(0.03,0.2,0.03);
		nodePuntaCanon04_2->scale(0.03,0.2,0.03);
		nodePuntaCanon04_1->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon04_2->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon04_1 -> translate(0.2,0,7);
		nodePuntaCanon04_2 -> translate(-0.2,0,7);
		/*
		nodePuntaCanon01_1->scale(0.05,0.8,0.05);
		nodePuntaCanon01_2->scale(0.05,0.8,0.05);
		nodePuntaCanon01_1->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_2->pitch(Ogre::Degree(270.0f));
		nodePuntaCanon01_1 -> translate(0.2,0,6.5);
		nodePuntaCanon01_2 -> translate(-0.2,0,6.5);
		*/
		//Crear Animacion de laTorreta 4
		Ogre::Entity* entLaser07 = mSceneMgr -> createEntity("entLaser07","usb_laser.mesh");
		nodeLaser07 = mSceneMgr->createSceneNode("nodoLaser07");
		nodeLaser07 -> attachObject(entLaser07);
		nodeCanon04 -> addChild(nodeLaser07);
		nodeLaser07->translate(0.2,0,6);
		nodeLaser07->pitch(Ogre::Degree(90.0f));
		nodeLaser07->scale(0.1,0.1,0.1);

		Ogre::Entity* entLaser08 = mSceneMgr -> createEntity("entLaser08","usb_laser.mesh");
		nodeLaser08= mSceneMgr->createSceneNode("nodoLaser08");
		nodeLaser08 -> attachObject(entLaser08);
		nodeCanon04 -> addChild(nodeLaser08);
		nodeLaser08->translate(-0.2,0,8);
		nodeLaser08->pitch(Ogre::Degree(90.0f));
		nodeLaser08->scale(0,0,0);
		 
		//Laser01		 
		 float duration4 = 3;		 
		 Ogre::Animation* animationTorreta04 = mSceneMgr -> createAnimation("animTorreta04",duration4);
		 animationTorreta04 -> setInterpolationMode(Animation::IM_SPLINE);
		 Ogre::NodeAnimationTrack* trackLaser07 = animationTorreta04->createNodeTrack(0,nodeLaser07);
		 key = trackLaser07 -> createNodeKeyFrame(0.0);
		 key -> setTranslate(Vector3(0.2,0,8));
		 key -> setScale(Vector3(0.1,0.1,0.1));
		 key -> setRotation(Quaternion(1,1,0,0));		
		 key = trackLaser07 -> createNodeKeyFrame(1.5);
		 key -> setTranslate(Vector3(0.2,0,442));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 key = trackLaser07 -> createNodeKeyFrame(3);
		 key -> setTranslate(Vector3(0.2,0,885));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 an1macionLaser07 = mSceneMgr -> createAnimationState("animTorreta04");
		 an1macionLaser07 -> setEnabled(true);
		 an1macionLaser07 -> setLoop(true);
		//Laser02		 		 
		 Ogre::Animation* animationTorreta04_1 = mSceneMgr -> createAnimation("animTorreta04_1",duration4);
		 animationTorreta04_1 -> setInterpolationMode(Animation::IM_SPLINE);
		 Ogre::NodeAnimationTrack* trackLaser08 = animationTorreta04_1->createNodeTrack(0,nodeLaser08);
		 key = trackLaser08 -> createNodeKeyFrame(0);
		 key -> setTranslate(Vector3(-0.2,0,8));
		 key -> setScale(Vector3(0.1,0.1,0.1));
		 key -> setRotation(Quaternion(1,1,0,0));		
		 key = trackLaser08-> createNodeKeyFrame(1.5);
		 key -> setTranslate(Vector3(-0.2,0,442));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 key = trackLaser08 -> createNodeKeyFrame(3);
		 key -> setTranslate(Vector3(-0.2,0,885));
		 key -> setScale(Vector3(0.2,0.2,0.2));
		 key -> setRotation(Quaternion(1,1,0,0));
		 an1macionLaser08 = mSceneMgr -> createAnimationState("animTorreta04_1");
		 an1macionLaser08 -> setEnabled(true);
		 an1macionLaser08 -> setLoop(true);


		
		
		 //CUADRICULA vater
		/*
		 Ogre:: Entity* entPlano = mSceneMgr -> createEntity("planoXEntity","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano1 = mSceneMgr -> createEntity("planoXEntity1","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano2 = mSceneMgr -> createEntity("planoXEntity2","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano3 = mSceneMgr -> createEntity("planoXEntity3","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano4 = mSceneMgr -> createEntity("planoXEntity4","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano5 = mSceneMgr -> createEntity("planoXEntity5","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano6 = mSceneMgr -> createEntity("planoXEntity6","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano7 = mSceneMgr -> createEntity("planoXEntity7","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano8 = mSceneMgr -> createEntity("planoXEntity8","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano9 = mSceneMgr -> createEntity("planoXEntity9","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano10 = mSceneMgr -> createEntity("planoXEntity10","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano11= mSceneMgr -> createEntity("planoXEntity11","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano12 = mSceneMgr -> createEntity("planoXEntity12","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano13 = mSceneMgr -> createEntity("planoXEntity13","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano14 = mSceneMgr -> createEntity("planoXEntity14","cuadriculaX01.mesh");
		 Ogre:: Entity* entPlano15 = mSceneMgr -> createEntity("planoXEntity15","cuadriculaX01.mesh");

		 Ogre:: SceneNode* nodePlanoX = mSceneMgr -> createSceneNode("nodePlanoX");
		 Ogre:: SceneNode* nodePlanoX1 = mSceneMgr -> createSceneNode("nodePlanoX1");
		 Ogre:: SceneNode* nodePlanoX2 = mSceneMgr -> createSceneNode("nodePlanoX2");
		 Ogre:: SceneNode* nodePlanoX3 = mSceneMgr -> createSceneNode("nodePlanoX3");
		 Ogre:: SceneNode* nodePlanoX4 = mSceneMgr -> createSceneNode("nodePlanoX4");
		 Ogre:: SceneNode* nodePlanoX5 = mSceneMgr -> createSceneNode("nodePlanoX5");
		 Ogre:: SceneNode* nodePlanoX6 = mSceneMgr -> createSceneNode("nodePlanoX6");
		 Ogre:: SceneNode* nodePlanoX7 = mSceneMgr -> createSceneNode("nodePlanoX7");
		 Ogre:: SceneNode* nodePlanoX8 = mSceneMgr -> createSceneNode("nodePlanoX8");
		 Ogre:: SceneNode* nodePlanoX9 = mSceneMgr -> createSceneNode("nodePlanoX9");
		 Ogre:: SceneNode* nodePlanoX10 = mSceneMgr -> createSceneNode("nodePlanoX10");
		 Ogre:: SceneNode* nodePlanoX11 = mSceneMgr -> createSceneNode("nodePlanoX11");
		 Ogre:: SceneNode* nodePlanoX12 = mSceneMgr -> createSceneNode("nodePlanoX12");
		 Ogre:: SceneNode* nodePlanoX13 = mSceneMgr -> createSceneNode("nodePlanoX13");
		 Ogre:: SceneNode* nodePlanoX14 = mSceneMgr -> createSceneNode("nodePlanoX14");
		 Ogre:: SceneNode* nodePlanoX15 = mSceneMgr -> createSceneNode("nodePlanoX15");

		 mSceneMgr -> getRootSceneNode() -> addChild(nodePlanoX); //Padre de todos =)
		 nodePlanoX -> attachObject(entPlano);
		 nodePlanoX1 -> attachObject(entPlano1);
		 nodePlanoX2 -> attachObject(entPlano2);
		 nodePlanoX3 -> attachObject(entPlano3);
		 nodePlanoX4 -> attachObject(entPlano4);
		 nodePlanoX5 -> attachObject(entPlano5);
		 nodePlanoX6 -> attachObject(entPlano6);
		 nodePlanoX7 -> attachObject(entPlano7);
		 nodePlanoX8 -> attachObject(entPlano8);
		 nodePlanoX9 -> attachObject(entPlano9);
		 nodePlanoX10 -> attachObject(entPlano10);
		 nodePlanoX11 -> attachObject(entPlano11);
		 nodePlanoX12 -> attachObject(entPlano12);
		 nodePlanoX13 -> attachObject(entPlano13);
		 nodePlanoX14 -> attachObject(entPlano14);
		 nodePlanoX15 -> attachObject(entPlano15);

		 nodePlanoX  -> addChild(nodePlanoX1);
		 nodePlanoX1 -> addChild(nodePlanoX2);
		 nodePlanoX2 -> addChild(nodePlanoX3);
		 nodePlanoX3 -> addChild(nodePlanoX4);
		 nodePlanoX4 -> addChild(nodePlanoX5);
		 nodePlanoX5 -> addChild(nodePlanoX6);
		 nodePlanoX6 -> addChild(nodePlanoX7);
		 nodePlanoX7 -> addChild(nodePlanoX8);
		 nodePlanoX8 -> addChild(nodePlanoX9);
		 nodePlanoX9 -> addChild(nodePlanoX10);
		 nodePlanoX10 -> addChild(nodePlanoX11);
		 nodePlanoX11 -> addChild(nodePlanoX12);
		 nodePlanoX12 -> addChild(nodePlanoX13);
		 nodePlanoX13 -> addChild(nodePlanoX14);
		 nodePlanoX14 -> addChild(nodePlanoX15);

		 nodePlanoX1 -> translate(0,0,-43);
		 nodePlanoX2 -> translate(0,0,-43);
		 nodePlanoX3 -> translate(0,0,-43);
		 nodePlanoX4 -> translate(0,0,-43);
		 nodePlanoX5 -> translate(0,0,-43);
		 nodePlanoX6 -> translate(0,0,-43);
		 nodePlanoX7 -> translate(0,0,-43);
		 nodePlanoX8 -> translate(0,0,-43);
		 nodePlanoX9 -> translate(0,0,-43);
		 nodePlanoX10 -> translate(0,0,-43);
		 nodePlanoX11 -> translate(0,0,-43);
		 nodePlanoX12 -> translate(0,0,-43);
		 nodePlanoX13 -> translate(0,0,-43);
		 nodePlanoX14 -> translate(0,0,-43);
		 nodePlanoX15 -> translate(0,0,-43);
		 */
		 
		

		Ogre::Entity* entEscena01 = mSceneMgr->createEntity("ogre_base01.mesh");
		mSceneMgr->getRootSceneNode()->attachObject(entEscena01);

		Ogre::Entity* entEscena02 = mSceneMgr->createEntity("ogre_fondo01.mesh");
		mSceneMgr->getRootSceneNode()->attachObject(entEscena02);

		Ogre::Entity* entEscena03 = mSceneMgr->createEntity("ogre_pared01.mesh");
		mSceneMgr->getRootSceneNode()->attachObject(entEscena03);

		Ogre::Entity* entEscena04 = mSceneMgr->createEntity("ogre_pared02.mesh");
		mSceneMgr->getRootSceneNode()->attachObject(entEscena04);

		Ogre::Entity* entEscena05 = mSceneMgr->createEntity("ogre_pared03.mesh");
		mSceneMgr->getRootSceneNode()->attachObject(entEscena05);

		Ogre::Entity* entEscena06 = mSceneMgr->createEntity("ogre_torretas01.mesh");
		mSceneMgr->getRootSceneNode()->attachObject(entEscena06);



	}

};


int main (void)
{

	Example1 app;
	app.go();
	return 0;
}