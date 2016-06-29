#include "ExampleApplication.h"
bool alasActivadas = false;
float rotNave = 0;
float expansion = 1;
float rotate = 0.0;

class FrameListenerClass : public Ogre::FrameListener{

private:
	OIS::InputManager* _man;
	Ogre::Camera* _cam;
	OIS::Keyboard* _key;
	OIS::Mouse* _mouse;
	Ogre::SceneNode* _nodoChasis;
	Ogre::SceneNode* _nodoLlanta01;
	Ogre::SceneNode* _nodoLlanta02;
	Ogre::SceneNode* _nodoLlanta03;
	Ogre::SceneNode* _nodoLlanta04;
	Ogre::SceneNode* _nodoMoneda1;
	Ogre::SceneNode* _nodoMoneda2;
	Ogre::SceneNode* _nodoMoneda3;
	Ogre::SceneNode* _nodoMoneda4;
	Ogre::SceneNode* _nodoMoneda5;
	Ogre::SceneNode* _nodoMoneda6;
	Ogre::SceneNode* _nodoMoneda7;
	Ogre::SceneNode* _nodoMoneda8;
	Ogre::SceneNode* _nodoMoneda9;
	Ogre::SceneNode* _nodoMoneda10;
	Ogre::SceneNode* _nodoMoneda11;
	Ogre::SceneNode* _nodoMoneda12;
	Ogre::SceneNode* _nodoMoneda13;
	Ogre::SceneNode* _nodoMoneda14;
	Ogre::SceneNode* _nodoMoneda15;
	Ogre::SceneNode* _nodoMoneda16;
	Ogre::SceneNode* _nodoMoneda17;
	Ogre::SceneNode* _nodoMoneda18;
	Ogre::SceneNode* _nodoObs1;
	Ogre::SceneNode* _nodeAlaSupDer;
	Ogre::SceneNode* _nodeAlaSupIzq;
	Ogre::SceneNode* _nodeAsteroide1;
	Ogre::SceneNode* _nodeAsteroide2;
	Ogre::SceneNode* _nodeAsteroide3;
	Ogre::SceneNode* _nodeAsteroide4;
	Ogre::SceneNode* _nodeAsteroide5;
	Ogre::SceneNode* _nodeAsteroide6;
	Ogre::SceneNode* _nodeMonedaVacio1;
	Ogre::SceneNode* _nodeMonedaVacio2;
	Ogre::SceneNode* _nodeMonedaVacio3;
	Ogre::SceneNode* _nodeMonedaVacio4;
	

public:
		
	FrameListenerClass(Ogre::SceneNode* nodoChasis, Ogre::SceneNode* nodoLlanta01, Ogre::SceneNode* nodoLlanta02,
						Ogre::SceneNode* nodoLlanta03, Ogre::SceneNode* nodoLlanta04,Ogre::SceneNode* nodoMoneda1,
						Ogre::SceneNode* nodoMoneda2,Ogre::SceneNode* nodoMoneda3,Ogre::SceneNode* nodoMoneda4,
						Ogre::SceneNode* nodoMoneda5,Ogre::SceneNode* nodoMoneda6,Ogre::SceneNode* nodoMoneda7,
						Ogre::SceneNode* nodoMoneda8,Ogre::SceneNode* nodoMoneda9,Ogre::SceneNode* nodoMoneda10,
						Ogre::SceneNode* nodoMoneda11,Ogre::SceneNode* nodoMoneda12,Ogre::SceneNode* nodoMoneda13,
						Ogre::SceneNode* nodoMoneda14,Ogre::SceneNode* nodoMoneda15,Ogre::SceneNode* nodoMoneda16,
						Ogre::SceneNode* nodoMoneda17,Ogre::SceneNode* nodoMoneda18,
						Ogre::SceneNode* nodoAlaSupDer,Ogre::SceneNode* nodoAlaSupIzq,
						Ogre::SceneNode* nodeAsteroide1,Ogre::SceneNode* nodeAsteroide2,Ogre::SceneNode* nodeAsteroide3,
						Ogre::SceneNode* nodeAsteroide4,Ogre::SceneNode* nodeAsteroide5,Ogre::SceneNode* nodeAsteroide6,
						Ogre::SceneNode* nodeMonedaVacio1,Ogre::SceneNode* nodeMonedaVacio2,Ogre::SceneNode* nodeMonedaVacio3,Ogre::SceneNode* nodeMonedaVacio4,
						Ogre::SceneNode* nodoObs1, Ogre::Camera* cam,  RenderWindow* win){
		size_t windowHnd = 0;
		std::stringstream windowHndStr;
		win->getCustomAttribute("WINDOW",&windowHnd);
		windowHndStr << windowHnd;

		OIS::ParamList pl;
		pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str())); 

		_man = OIS::InputManager::createInputSystem(pl);
		_key= static_cast<OIS::Keyboard*>(_man->createInputObject(OIS::OISKeyboard,false));
		_mouse= static_cast<OIS::Mouse*>(_man->createInputObject(OIS::OISMouse,false));
		_cam = cam;
		// Nodo para la cabina
		_nodoChasis = nodoChasis;
		// Nodos para cada rueda
		_nodoLlanta01 = nodoLlanta01;
		_nodoLlanta02 = nodoLlanta02;
		_nodoLlanta03 = nodoLlanta03;
		_nodoLlanta04 = nodoLlanta04;
		_nodoMoneda1  = nodoMoneda1;
		_nodoMoneda2  = nodoMoneda2;
		_nodoMoneda3  = nodoMoneda3;
		_nodoMoneda4  = nodoMoneda4;
		_nodoMoneda5  = nodoMoneda5;
		_nodoMoneda6  = nodoMoneda6;
		_nodoMoneda7  = nodoMoneda7;
		_nodoMoneda8  = nodoMoneda8;
		_nodoMoneda9  = nodoMoneda9;
		_nodoMoneda10  = nodoMoneda10;
		_nodoMoneda11  = nodoMoneda11;
		_nodoMoneda12  = nodoMoneda12;
		_nodoMoneda13  = nodoMoneda13;
		_nodoMoneda14  = nodoMoneda14;
		_nodoMoneda15  = nodoMoneda15;
		_nodoMoneda16  = nodoMoneda16;
		_nodoMoneda17  = nodoMoneda17;
		_nodoMoneda18  = nodoMoneda18;
		_nodoObs1 = nodoObs1;
		// Nodo para alas
		_nodeAlaSupDer = nodoAlaSupDer;
		_nodeAlaSupIzq = nodoAlaSupIzq;
		//asteroides
		_nodeAsteroide1 = nodeAsteroide1;
		_nodeAsteroide2 = nodeAsteroide2;
		_nodeAsteroide3 = nodeAsteroide3;
		_nodeAsteroide4 = nodeAsteroide4;
		_nodeAsteroide5 = nodeAsteroide5;
		_nodeAsteroide6 = nodeAsteroide6;
		//monedas del vacio
		_nodeMonedaVacio1 =nodeMonedaVacio1;
		_nodeMonedaVacio2 =nodeMonedaVacio2;
		_nodeMonedaVacio3 =nodeMonedaVacio3;
		_nodeMonedaVacio4 =nodeMonedaVacio4;
	}

	~FrameListenerClass(){
		_man->destroyInputObject(_key);
		_man->destroyInputObject(_mouse);
		OIS::InputManager::destroyInputSystem(_man);
	}

	void colisionMonedas(int i, int f, Ogre::Vector3 posicionCar){
        bool colicion=false;
        //variable para las colisiones
        float minPosCx = posicionCar.x;
        float maxPosCx = posicionCar.x;
        float minPosCy = posicionCar.y;
        float maxPosCy = posicionCar.y;
        float minPosCz = posicionCar.z;
        float maxPosCz = posicionCar.z;

    }
	bool frameStarted(const Ogre::FrameEvent &evt){
		_key->capture();
		_mouse->capture();
		Ogre::Vector3 posicionCar = _nodoChasis->getPosition();

		float movSpeed = 10.0f;
		Ogre::Vector3 tmov(0,0,0);
		Ogre::Vector3 tobs(0,0,0);
		Ogre::Vector3 tcam(0,0,0);

		float rotLlanta = 0.0;
		float rotCoin = 0.0;
		Ogre::Vector3 newPosCar = tmov*movSpeed*evt.timeSinceLastFrame;
		Real xPosChasis = _nodoChasis->getPosition().x;
		Real zPosChasis = _nodoChasis->getPosition().z;
		bool xDer;
		bool xIzq;

		//Lado Derecho
		if (xPosChasis>-110.0	&& zPosChasis<420.0){
			xDer = true;
		}else if (xPosChasis>-190.0	&& zPosChasis>=420.0	&& zPosChasis<2400.0){
			xDer = true;
		}else if (xPosChasis>-20.0	&& zPosChasis>=2900.0	&& zPosChasis<4900.0){
			xDer = true;
		}else if (xPosChasis>-190.0	&& zPosChasis>=4900.0){
			xDer = true;
		}else {
			xDer = false;
		}

		//Lado Izquierdo
		if (xPosChasis<=115.0	&& zPosChasis<420.0){
			xIzq = true;
		}else if (xPosChasis<=195.0	&& zPosChasis>=420.0	&& zPosChasis<2400.0){
			xIzq = true;
		}else if (xPosChasis<=25.0	&& zPosChasis>=2900.0	&& zPosChasis<4900.0){
			xIzq = true;
		}else if (xPosChasis<=195.0	&& zPosChasis>=4900.0){
			xIzq = true;
		}else {
			xIzq = false;
		}
		
		if(_key->isKeyDown(OIS::KC_ESCAPE))
			return false;
		//vehiculo
		if(_key->isKeyDown(OIS::KC_UP)){
			if (_nodoChasis->getPosition().z > 6526 && _nodoChasis->getPosition().y < 500 && alasActivadas){
				tmov += Ogre::Vector3(0,10,0);
			}
		}
		if(_key->isKeyDown(OIS::KC_DOWN)){
			if (_nodoChasis->getPosition().z > 6526 && _nodoChasis->getPosition().y > -500 && alasActivadas){
				tmov += Ogre::Vector3(0,-10,0);
			}
		}
		if(_key->isKeyDown(OIS::KC_W)){
			tmov += Ogre::Vector3(0,0,10);
			rotLlanta+=10;
		}

		if(_key->isKeyDown(OIS::KC_A)){
			if ( _nodoChasis->getPosition().z > 6526)// estamos en el espacio
			{			
				//Limite izquierdo del espacio: 190
					if (_nodoChasis->getPosition().x < 190)
					{
						tmov += Ogre::Vector3(10,0,0);
						if(rotNave >= -45){
							rotNave -= 5;
							_nodoChasis -> roll(Ogre::Degree(-5));
						}
						
						
					}
			}
			else{//No estamos en el espacio
				if (xIzq==true){
					if(rotate < 45 && xDer==true){
						rotate += 5.0;
						_nodoChasis->yaw(Ogre::Degree(5));
					}
					tmov += Ogre::Vector3(10,0,0);
				}
			}
		}
		if(_key->isKeyDown(OIS::KC_D)){
			if ( _nodoChasis->getPosition().z > 6526)//estamos en el espacio
			{		
					//Limite derecho del espacio: -190
					if (_nodoChasis->getPosition().x > -190)
					{
						tmov += Ogre::Vector3(-10,0,0);
						if(rotNave <= 45){
							rotNave += 5;
							_nodoChasis -> roll(Ogre::Degree(5));
						}					
					}			
			}
			else{//No estamos en el espacio
				if (xDer==true){
					if(rotate > -45 && xDer==true ){
						rotate -= 5.0;
						_nodoChasis->yaw(Ogre::Degree(-5));
					}
					tmov += Ogre::Vector3(-10,0,0);
				}
			}
		}
		if(_key->isKeyDown(OIS::KC_S)){
			tmov += Ogre::Vector3(0,0,-10);
		}

		//Desplegar alas y notificar que ya estariamos volando
		if ( (_nodoChasis->getPosition().z > 6300) && !(alasActivadas))
		{
			alasActivadas = true;
			
		}
		//Colocar el carro como si no se le hubiese rotado
		if (_nodoChasis->getPosition().z > 6526 && _nodoChasis->getPosition().z < 6535 && alasActivadas){
			_nodoChasis->setOrientation(Quaternion());
			rotate = 0;
			rotNave = 0;
		}


		_nodoLlanta01->rotate(Ogre::Quaternion(Ogre::Degree(rotLlanta*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(1,0,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoLlanta02->rotate(Ogre::Quaternion(Ogre::Degree(rotLlanta*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(1,0,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoLlanta03->rotate(Ogre::Quaternion(Ogre::Degree(rotLlanta*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(1,0,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoLlanta04->rotate(Ogre::Quaternion(Ogre::Degree(rotLlanta*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(1,0,0)) , Ogre::Node::TransformSpace::TS_WORLD);

		float rotX = _mouse->getMouseState().X.rel * evt.timeSinceLastFrame * -1;
		float rotY = _mouse->getMouseState().Y.rel * evt.timeSinceLastFrame * -1;
		_cam->yaw(Ogre::Radian(rotX));
		_cam->pitch(Ogre::Radian(rotY));
		_cam->setPosition(_nodoChasis->getPosition().x,_nodoChasis->getPosition().y+25.0,_nodoChasis->getPosition().z-70.0);

		if (alasActivadas)
		{
			if (expansion < 75)
			{			
				_nodeAlaSupDer -> scale(1,1.1,1);
				_nodeAlaSupIzq -> scale(1,1.1,1);
				expansion++;
			}
			

		}

		//_nodoChasis->rotate(Ogre::Quaternion(Ogre::Degree(rotate* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoChasis->translate(tmov*movSpeed* evt.timeSinceLastFrame);
		
		rotCoin += 5;
		_nodoMoneda1->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda2->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda3->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda4->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda5->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda6->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda7->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda8->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda9->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda10->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda11->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda12->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda13->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda14->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda15->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda16->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda17->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);
		_nodoMoneda18->rotate(Ogre::Quaternion(Ogre::Degree(rotCoin*movSpeed* evt.timeSinceLastFrame), Ogre::Vector3(0,1,0)) , Ogre::Node::TransformSpace::TS_WORLD);

		//animacion asteroides
		_nodeAsteroide1->yaw(Ogre::Degree(5));
		_nodeAsteroide2->yaw(Ogre::Degree(-2));
		_nodeAsteroide3->yaw(Ogre::Degree(2));
		_nodeAsteroide4->yaw(Ogre::Degree(3));
		_nodeAsteroide5->yaw(Ogre::Degree(-3));
		_nodeAsteroide6->yaw(Ogre::Degree(1));
		//animacion monedas vacio
		_nodeMonedaVacio1 -> yaw(Ogre::Degree(5));
		_nodeMonedaVacio2 -> yaw(Ogre::Degree(5));
		_nodeMonedaVacio3 -> yaw(Ogre::Degree(5));
		_nodeMonedaVacio4 -> yaw(Ogre::Degree(5));
		
		return true;
	}


};

class Example1 : public ExampleApplication
{

public:
	Ogre::SceneNode* _nodeEjeChasis;
	Ogre::SceneNode* _nodeChasis01;
	Ogre::SceneNode* _nodeRueda01;
	Ogre::SceneNode* _nodeRueda02;
	Ogre::SceneNode* _nodeRueda03;
	Ogre::SceneNode* _nodeRueda04;
	Ogre::SceneNode* _nodeMoneda1;
	Ogre::SceneNode* _nodeMoneda2;
	Ogre::SceneNode* _nodeMoneda3;
	Ogre::SceneNode* _nodeMoneda4;
	Ogre::SceneNode* _nodeMoneda5;
	Ogre::SceneNode* _nodeMoneda6;
	Ogre::SceneNode* _nodeMoneda7;
	Ogre::SceneNode* _nodeMoneda8;
	Ogre::SceneNode* _nodeMoneda9;
	Ogre::SceneNode* _nodeMoneda10;
	Ogre::SceneNode* _nodeMoneda11;
	Ogre::SceneNode* _nodeMoneda12;
	Ogre::SceneNode* _nodeMoneda13;
	Ogre::SceneNode* _nodeMoneda14;
	Ogre::SceneNode* _nodeMoneda15;
	Ogre::SceneNode* _nodeMoneda16;
	Ogre::SceneNode* _nodeMoneda17;
	Ogre::SceneNode* _nodeMoneda18;
	Ogre::SceneNode* _nodePen;
	Ogre::SceneNode* _nodeObs1;
	Ogre::SceneNode* _nodeAlaSupDer;
	Ogre::SceneNode* _nodeAlaSupIzq;
	Ogre::SceneNode* _nodeAsteroide1;
	Ogre::SceneNode* _nodeAsteroide2;
	Ogre::SceneNode* _nodeAsteroide3;
	Ogre::SceneNode* _nodeAsteroide4;
	Ogre::SceneNode* _nodeAsteroide5;
	Ogre::SceneNode* _nodeAsteroide6;
	Ogre::SceneNode* _nodeMonedaVacio1;
	Ogre::SceneNode* _nodeMonedaVacio2;
	Ogre::SceneNode* _nodeMonedaVacio3;
	Ogre::SceneNode* _nodeMonedaVacio4;
	Ogre::FrameListener* FrameListener01;

	Example1(){
		FrameListener01 = NULL;
	}

	~Example1(){
		if (FrameListener01){
			delete FrameListener01;
		}
	}
	
	void createFrameListener(){
		FrameListener01 = new FrameListenerClass(_nodeChasis01,_nodeRueda01,_nodeRueda02,_nodeRueda03,_nodeRueda04,_nodeMoneda1,_nodeMoneda2,
												_nodeMoneda3,_nodeMoneda4,_nodeMoneda5,_nodeMoneda6,_nodeMoneda7,_nodeMoneda8,_nodeMoneda9,_nodeMoneda10,
												_nodeMoneda11,_nodeMoneda12,_nodeMoneda13,_nodeMoneda14,_nodeMoneda15,_nodeMoneda16,_nodeMoneda17,_nodeMoneda18,
												_nodeAlaSupDer, _nodeAlaSupIzq,
												 _nodeAsteroide1,_nodeAsteroide2,_nodeAsteroide3,_nodeAsteroide4,_nodeAsteroide5,_nodeAsteroide6,
												 _nodeMonedaVacio1,_nodeMonedaVacio2,_nodeMonedaVacio3,_nodeMonedaVacio4,
												_nodeObs1, mCamera,mWindow);
		mRoot->addFrameListener(FrameListener01);
	}


	void createCamera() {

		mCamera = mSceneMgr->createCamera("MyCamera1");
		mCamera->setPosition(0,100,-200);
		mCamera->lookAt(0,0,100);
		mCamera->setNearClipDistance(1);

	}

	void createScene()
	{

		mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));
		mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
		
		Ogre::Light* LuzPuntual01 = mSceneMgr->createLight("Luz01");
		LuzPuntual01->setType(Ogre::Light::LT_DIRECTIONAL);
		LuzPuntual01->setDiffuseColour(1.0,1.0,1.0);
		LuzPuntual01->setDirection(Ogre::Vector3( 1, -1, -1 ));
		
		Ogre::Light* LuzPuntual02 = mSceneMgr->createLight("Luz02");
		LuzPuntual02->setType(Ogre::Light::LT_DIRECTIONAL);
		LuzPuntual02->setDiffuseColour(1.0,1.0,1.0);
		LuzPuntual02->setDirection(Ogre::Vector3( -1, -1, -1 ));

		
		Ogre::Light* LuzPuntual03 = mSceneMgr->createLight("Luz03");
		LuzPuntual03->setType(Ogre::Light::LT_POINT);
		LuzPuntual03->setDiffuseColour(1.0,1.0,1.0);
		LuzPuntual03->setPosition( 0, 100, 8000 );

		Ogre::Light* LucesPuntuales[19];
        int posicion = 3000;
        for (int i = 0; i < 19; ++i) {
            LucesPuntuales[i] = mSceneMgr->createLight();
            LucesPuntuales[i]->setType(Ogre::Light::LT_POINT);
            LucesPuntuales[i]->setDiffuseColour(60.0,60.0,60.0);
            LucesPuntuales[i]->setPosition(Ogre::Vector3(0.0,3,posicion));
            LucesPuntuales[i]->setCastShadows(true);
            LucesPuntuales[i]->setAttenuation(50, 1.0, 0.1, 0.0);

            posicion = posicion + 100;
		}

		//Text monedas
		Ogre::MaterialPtr coin = Ogre::MaterialManager::getSingleton().create(
		"CilindroText", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

		Ogre::TextureUnitState* coinTexture =
		coin ->getTechnique(0) ->getPass(0)->createTextureUnitState("coin.jpg");

		//Asteroides:
		//01
		Ogre::Entity* _entAsteroide1 = mSceneMgr->createEntity("entAsteroide1", "roca01.mesh");
		_entAsteroide1->setMaterialName("lambert1");
		_nodeAsteroide1 = mSceneMgr->createSceneNode("nodeAsteroide1");
		mSceneMgr->getRootSceneNode()->addChild(_nodeAsteroide1);
		_nodeAsteroide1->attachObject(_entAsteroide1);
		_nodeAsteroide1->setPosition(75,0,7000);
		//02
		Ogre::Entity* _entAsteroide2 = mSceneMgr->createEntity("entAsteroide2", "roca02.mesh");
		_entAsteroide2->setMaterialName("lambert1");
		_nodeAsteroide2 = mSceneMgr->createSceneNode("nodeAsteroide2");
		mSceneMgr->getRootSceneNode()->addChild(_nodeAsteroide2);
		_nodeAsteroide2->attachObject(_entAsteroide2);
		_nodeAsteroide2->setPosition(-75,0,7500);
		//03
		Ogre::Entity* _entAsteroide3 = mSceneMgr->createEntity("entAsteroide3", "roca03.mesh");
		_entAsteroide3->setMaterialName("lambert1");
		_nodeAsteroide3 = mSceneMgr->createSceneNode("nodeAsteroide3");
		mSceneMgr->getRootSceneNode()->addChild(_nodeAsteroide3);
		_nodeAsteroide3->attachObject(_entAsteroide3);
		_nodeAsteroide3->setPosition(0,0,8000);
		//04
		Ogre::Entity* _entAsteroide4 = mSceneMgr->createEntity("entAsteroide4", "roca04.mesh");
		_entAsteroide4->setMaterialName("lambert1");
		_nodeAsteroide4 = mSceneMgr->createSceneNode("nodeAsteroide4");
		mSceneMgr->getRootSceneNode()->addChild(_nodeAsteroide4);
		_nodeAsteroide4->attachObject(_entAsteroide4);
		_nodeAsteroide4->setPosition(75,0,8500);
		//05
		Ogre::Entity* _entAsteroide5 = mSceneMgr->createEntity("entAsteroide5", "roca01.mesh");
		_entAsteroide5->setMaterialName("lambert1");
		_nodeAsteroide5 = mSceneMgr->createSceneNode("nodeAsteroide5");
		mSceneMgr->getRootSceneNode()->addChild(_nodeAsteroide5);
		_nodeAsteroide5->attachObject(_entAsteroide5);
		_nodeAsteroide5->setPosition(-100,0,9000);
		//06
		Ogre::Entity* _entAsteroide6 = mSceneMgr->createEntity("entAsteroide6", "roca04.mesh");
		_entAsteroide6->setMaterialName("lambert1");
		_nodeAsteroide6 = mSceneMgr->createSceneNode("nodeAsteroide6");
		mSceneMgr->getRootSceneNode()->addChild(_nodeAsteroide6);
		_nodeAsteroide6->attachObject(_entAsteroide6);
		_nodeAsteroide6->setPosition(0,0,9500);

		//Monedas del vacio
		_nodeMonedaVacio1 = mSceneMgr->createSceneNode("nodeMonedaVacio1");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMonedaVacio1);
		Ogre::Entity* _MonedaVacio1 = mSceneMgr->createEntity("entMonedaVacio1", "sphere.mesh");
		_MonedaVacio1->setMaterial(coin);
		_nodeMonedaVacio1->attachObject(_MonedaVacio1);
		_nodeMonedaVacio1->setScale(0.08,0.08,0.05);
		_nodeMonedaVacio1->setPosition(30,0,7250);

		_nodeMonedaVacio2 = mSceneMgr->createSceneNode("nodeMonedaVacio2");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMonedaVacio2);
		Ogre::Entity* _MonedaVacio2 = mSceneMgr->createEntity("entMonedaVacio2", "sphere.mesh");
		_MonedaVacio2->setMaterial(coin);
		_nodeMonedaVacio2->attachObject(_MonedaVacio2);
		_nodeMonedaVacio2->setScale(0.08,0.08,0.05);
		_nodeMonedaVacio2->setPosition(-80,0,8250);

		_nodeMonedaVacio3 = mSceneMgr->createSceneNode("nodeMonedaVacio3");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMonedaVacio3);
		Ogre::Entity* _MonedaVacio3 = mSceneMgr->createEntity("entMonedaVacio3", "sphere.mesh");
		_MonedaVacio3->setMaterial(coin);
		_nodeMonedaVacio3->attachObject(_MonedaVacio3);
		_nodeMonedaVacio3->setScale(0.08,0.08,0.05);
		_nodeMonedaVacio3->setPosition(0,0,9000);

		_nodeMonedaVacio4 = mSceneMgr->createSceneNode("nodeMonedaVacio4");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMonedaVacio4);
		Ogre::Entity* _MonedaVacio4 = mSceneMgr->createEntity("entMonedaVacio4", "sphere.mesh");
		_MonedaVacio4->setMaterial(coin);
		_nodeMonedaVacio4->attachObject(_MonedaVacio4);
		_nodeMonedaVacio4->setScale(0.08,0.08,0.05);
		_nodeMonedaVacio4->setPosition(100,0,9250);

		//Chasis
		_nodeChasis01 = mSceneMgr->createSceneNode("Chasis01");
		mSceneMgr->getRootSceneNode()->addChild(_nodeChasis01);
			
		Ogre::Entity* _entChasis01 = mSceneMgr->createEntity("entChasis01", "chasisCarro.mesh");
		_entChasis01->setMaterialName("shCarro01");
		_nodeChasis01->attachObject(_entChasis01);
		//ALAS:
		_nodeAlaSupDer = mSceneMgr->createSceneNode("nodeAlaSupDer");
		_nodeChasis01 -> addChild(_nodeAlaSupDer);
		
		_nodeAlaSupIzq = mSceneMgr->createSceneNode("nodeAlaSupIzq");
		_nodeChasis01 -> addChild(_nodeAlaSupIzq);
		//Ala Derecha
		Ogre:: Entity* entAlaSuperiorDerecha = mSceneMgr -> createEntity("entAlaSuperiorDerecha","cubo02.mesh");
		entAlaSuperiorDerecha->setMaterialName("shCarro01");
		Ogre::SceneNode* nodeAlaSuperiorDerecha = mSceneMgr->createSceneNode("nodeAlaSuperiorDerecha");

		nodeAlaSuperiorDerecha -> attachObject(entAlaSuperiorDerecha);
		_nodeAlaSupDer -> addChild(nodeAlaSuperiorDerecha);

		_nodeAlaSupDer -> setPosition(0,5,-1);
		_nodeAlaSupDer -> translate(-3,0,0);
		_nodeAlaSupDer -> roll(Ogre::Degree(90));
		nodeAlaSuperiorDerecha -> translate(0,5,0);
		nodeAlaSuperiorDerecha -> scale(0.125,0.125,0.125);
		nodeAlaSuperiorDerecha -> scale(1,8,8);
		_nodeAlaSupDer -> scale(1,0.001,1);

		//Ala Izquierda
		Ogre:: Entity* entAlaSuperiorIzquierda = mSceneMgr -> createEntity("entAlaSuperiorIzquierda","cubo02.mesh");
		entAlaSuperiorIzquierda->setMaterialName("shCarro01");
		Ogre::SceneNode* nodeAlaSuperiorIzquierda = mSceneMgr->createSceneNode("nodeAlaSuperiorIzquierda");

		nodeAlaSuperiorIzquierda -> attachObject(entAlaSuperiorIzquierda);
		_nodeAlaSupIzq->addChild(nodeAlaSuperiorIzquierda);
		_nodeAlaSupIzq -> setPosition(0,5,-1);
		_nodeAlaSupIzq -> translate(3,0,0);
		_nodeAlaSupIzq -> roll(Ogre::Degree(-90));
		nodeAlaSuperiorIzquierda -> translate(0,5,0);
		nodeAlaSuperiorIzquierda -> scale(0.125,0.125,0.125);
		nodeAlaSuperiorIzquierda -> scale(1,8,8);
		_nodeAlaSupIzq -> scale(1,0.001,1);

		//Rueda derecha trasera
		_nodeRueda01 = mSceneMgr->createSceneNode("Rueda01");
		_nodeChasis01->addChild(_nodeRueda01);
			
		Ogre::Entity* _entRueda01 = mSceneMgr->createEntity("entRueda01", "ruedaDetallada.mesh");
		_nodeRueda01->translate(-5.77,3.517,-9.462);
		_entRueda01->setMaterialName("shRueda02");
		_nodeRueda01->attachObject(_entRueda01);

		//Rueda derecha delantera
		 _nodeRueda02 = mSceneMgr->createSceneNode("Rueda02");
		_nodeChasis01->addChild(_nodeRueda02);
			
		Ogre::Entity* _entRueda02 = mSceneMgr->createEntity("entRueda02", "ruedaDetallada.mesh");
		_nodeRueda02->translate(-5.77,3.517,9.462);
		_entRueda02->setMaterialName("shRueda02");
		_nodeRueda02->attachObject(_entRueda02);

		//Rueda izquierda trasera
		_nodeRueda03 = mSceneMgr->createSceneNode("Rueda03");
		_nodeChasis01->addChild(_nodeRueda03);
			
		Ogre::Entity* _entRueda03 = mSceneMgr->createEntity("entRueda03", "ruedaDetallada.mesh");
		_nodeRueda03->translate(7.77,3.517,-9.462);
		_entRueda03->setMaterialName("shRueda02");
		_nodeRueda03->attachObject(_entRueda03);

		//Rueda izquierda delantera
		 _nodeRueda04 = mSceneMgr->createSceneNode("Rueda04");
		_nodeChasis01->addChild(_nodeRueda04);
			
		Ogre::Entity* _entRueda04 = mSceneMgr->createEntity("entRueda04", "ruedaDetallada.mesh");
		_nodeRueda04->translate(7.77,3.517,9.462);
		_entRueda04->setMaterialName("shRueda02");
		_nodeRueda04->attachObject(_entRueda04);

		//BordePista
		Ogre::MaterialPtr borde = Ogre::MaterialManager::getSingleton().create(
		"CilindroText", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

		Ogre::TextureUnitState* bordeTexture =
		borde ->getTechnique(0) ->getPass(0)->createTextureUnitState("dirt01.jpg");

		Ogre::SceneNode* _nodeBPista = mSceneMgr->createSceneNode("BordePista");
		mSceneMgr->getRootSceneNode()->addChild(_nodeBPista);
				
		Ogre::Entity* _entBPista = mSceneMgr->createEntity("BordePista01", "bordePista.mesh");
		_nodeBPista->attachObject(_entBPista);
		_entBPista->setMaterial(borde);
	

		//PisoObstaculo
		Ogre::MaterialPtr piso = Ogre::MaterialManager::getSingleton().create(
		"CilindroText", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

		Ogre::TextureUnitState* pisoTexture =
		piso ->getTechnique(0) ->getPass(0)->createTextureUnitState("dirt01.jpg");

		Ogre::SceneNode* _nodePObstaculo = mSceneMgr->createSceneNode("PistaObstaculo");
		mSceneMgr->getRootSceneNode()->addChild(_nodePObstaculo);
				
		Ogre::Entity* _entPObstaculo = mSceneMgr->createEntity("PistaObstaculo", "pisoObstaculo01.mesh");
		_nodePObstaculo->attachObject(_entPObstaculo);
		_entPObstaculo->setMaterial(piso);
		
		//PisoNOObstaculo
		Ogre::MaterialPtr pisoNo = Ogre::MaterialManager::getSingleton().create(
		"CilindroText", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		
		Ogre::TextureUnitState* pisoNoTexture =
		pisoNo ->getTechnique(0) ->getPass(0)->createTextureUnitState("Dirt.jpg");
	
		Ogre::SceneNode* _nodePNObstaculo = mSceneMgr->createSceneNode("PistaNoObstaculo");
		mSceneMgr->getRootSceneNode()->addChild(_nodePNObstaculo);
				
		Ogre::Entity* _entPNOObstaculo = mSceneMgr->createEntity("PistaNoObstaculo", "pisoNoObstaculo01.mesh");
		_nodePNObstaculo->attachObject(_entPNOObstaculo);
		_entPNOObstaculo->setMaterial(pisoNo);


		//PosterInicioFinal
		Ogre::SceneNode* _nodePoster = mSceneMgr->createSceneNode("PosterInicioFinal");
		mSceneMgr->getRootSceneNode()->addChild(_nodePoster);
			
		Ogre::Entity* _entPoster = mSceneMgr->createEntity("PosterInicioFinal", "posterInicioFinal.mesh");
		_nodePoster->attachObject(_entPoster);

				
		//BanderaInicial
		Ogre::SceneNode* _nodeBInicial = mSceneMgr->createSceneNode("BanderaInicial");
		mSceneMgr->getRootSceneNode()->addChild(_nodeBInicial);
				
		Ogre::Entity* _entBanderaI = mSceneMgr->createEntity("BanderaInicial", "banderaInicial.mesh");				
		_entBanderaI->setMaterialName("lambert1");				
		_nodeBInicial->attachObject(_entBanderaI);


		//BanderaFinal
		Ogre::SceneNode* _nodeBFinal = mSceneMgr->createSceneNode("BanderaFinal");
		mSceneMgr->getRootSceneNode()->addChild(_nodeBFinal);
		
		Ogre::Entity* _entBanderaF = mSceneMgr->createEntity("BanderaFinal", "banderaFinal.mesh");
		_entBanderaF->setMaterialName("lambert1");
		_nodeBFinal->attachObject(_entBanderaF);


		//Pinguino
		_nodePen = mSceneMgr->createSceneNode("Pen");
		mSceneMgr->getRootSceneNode()->addChild(_nodePen);
		Ogre::Entity* _Pen = mSceneMgr->createEntity("Pen", "penguin.mesh");
		_Pen->setMaterial(coin);
		_nodePen->attachObject(_Pen);
		_nodePen->setScale(3.08,3.08,3.05);
		_nodePen->translate(10.77,110.517,3050.262);

		//Monedas
		_nodeMoneda1 = mSceneMgr->createSceneNode("Moneda1");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda1);
		Ogre::Entity* _Moneda1 = mSceneMgr->createEntity("Moneda", "sphere.mesh");
		_Moneda1->setMaterial(coin);
		_nodeMoneda1->attachObject(_Moneda1);
		_nodeMoneda1->setScale(0.08,0.08,0.05);
		_nodeMoneda1->translate(-5.77,7.517,200.262);

		_nodeMoneda2 = mSceneMgr->createSceneNode("Moneda2");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda2);
		Ogre::Entity* _Moneda2 = mSceneMgr->createEntity("Moneda2", "sphere.mesh");
		_Moneda2->setMaterial(coin);
		_nodeMoneda2->attachObject(_Moneda2);
		_nodeMoneda2->setScale(0.08,0.08,0.05);
		_nodeMoneda2->translate(-10.77,7.517,500.262);

		_nodeMoneda3 = mSceneMgr->createSceneNode("Moneda3");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda3);
		Ogre::Entity* _Moneda3 = mSceneMgr->createEntity("Moneda3", "sphere.mesh");
		_Moneda3->setMaterial(coin);
		_nodeMoneda3->attachObject(_Moneda3);
		_nodeMoneda3->setScale(0.08,0.08,0.05);
		_nodeMoneda3->translate(-15.77,7.517,800.262);

		_nodeMoneda4 = mSceneMgr->createSceneNode("Moneda4");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda4);
		Ogre::Entity* _Moneda4 = mSceneMgr->createEntity("Moneda4", "sphere.mesh");
		_Moneda4->setMaterial(coin);
		_nodeMoneda4->attachObject(_Moneda4);
		_nodeMoneda4->setScale(0.08,0.08,0.05);
		_nodeMoneda4->translate(-25.77,7.517,1000.262);

		_nodeMoneda5 = mSceneMgr->createSceneNode("Moneda5");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda5);
		Ogre::Entity* _Moneda5 = mSceneMgr->createEntity("Moneda5", "sphere.mesh");
		_Moneda5->setMaterial(coin);
		_nodeMoneda5->attachObject(_Moneda5);
		_nodeMoneda5->setScale(0.08,0.08,0.05);
		_nodeMoneda5->translate(0.77,7.517,1300.262);

		_nodeMoneda6 = mSceneMgr->createSceneNode("Moneda6");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda6);
		Ogre::Entity* _Moneda6 = mSceneMgr->createEntity("Moneda6", "sphere.mesh");
		_Moneda6->setMaterial(coin);
		_nodeMoneda6->attachObject(_Moneda6);
		_nodeMoneda6->setScale(0.08,0.08,0.05);
		_nodeMoneda6->translate(50.77,7.517,1700.262);

		_nodeMoneda7 = mSceneMgr->createSceneNode("Moneda7");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda7);
		Ogre::Entity* _Moneda7 = mSceneMgr->createEntity("Moneda7", "sphere.mesh");
		_Moneda7->setMaterial(coin);
		_nodeMoneda7->attachObject(_Moneda7);
		_nodeMoneda7->setScale(0.08,0.08,0.05);
		_nodeMoneda7->translate(0.77,7.517,2500.262);

		_nodeMoneda8 = mSceneMgr->createSceneNode("Moneda8");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda8);
		Ogre::Entity* _Moneda8 = mSceneMgr->createEntity("Moneda8", "sphere.mesh");
		_Moneda8->setMaterial(coin);
		_nodeMoneda8->attachObject(_Moneda8);
		_nodeMoneda8->setScale(0.08,0.08,0.05);
		_nodeMoneda8->translate(50.77,7.517,2800.262);

		_nodeMoneda9 = mSceneMgr->createSceneNode("Moneda9");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda9);
		Ogre::Entity* _Moneda9 = mSceneMgr->createEntity("Moneda9", "sphere.mesh");
		_Moneda9->setMaterial(coin);
		_nodeMoneda9->attachObject(_Moneda9);
		_nodeMoneda9->setScale(0.08,0.08,0.05);
		_nodeMoneda9->translate(0.77,7.517,3050.262);

		_nodeMoneda10 = mSceneMgr->createSceneNode("Moneda10");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda10);
		Ogre::Entity* _Moneda10 = mSceneMgr->createEntity("Moneda10", "sphere.mesh");
		_Moneda10->setMaterial(coin);
		_nodeMoneda10->attachObject(_Moneda10);
		_nodeMoneda10->setScale(0.08,0.08,0.05);
		_nodeMoneda10->translate(0.77,7.517,3250.262);

		_nodeMoneda11 = mSceneMgr->createSceneNode("Moneda11");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda11);
		Ogre::Entity* _Moneda11 = mSceneMgr->createEntity("Moneda11", "sphere.mesh");
		_Moneda11->setMaterial(coin);
		_nodeMoneda11->attachObject(_Moneda11);
		_nodeMoneda11->setScale(0.08,0.08,0.05);
		_nodeMoneda11->translate(0.77,7.517,3700.262);
		
		_nodeMoneda12 = mSceneMgr->createSceneNode("Moneda12");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda12);
		Ogre::Entity* _Moneda12 = mSceneMgr->createEntity("Moneda12", "sphere.mesh");
		_Moneda12->setMaterial(coin);
		_nodeMoneda12->attachObject(_Moneda12);
		_nodeMoneda12->setScale(0.08,0.08,0.05);
		_nodeMoneda12->translate(0.77,7.517,4000.262);

		_nodeMoneda13 = mSceneMgr->createSceneNode("Moneda13");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda13);
		Ogre::Entity* _Moneda13 = mSceneMgr->createEntity("Moneda13", "sphere.mesh");
		_Moneda13->setMaterial(coin);
		_nodeMoneda13->attachObject(_Moneda13);
		_nodeMoneda13->setScale(0.08,0.08,0.05);
		_nodeMoneda13->translate(0.77,7.517,4500.262);

		 _nodeMoneda14 = mSceneMgr->createSceneNode("Moneda14");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda14);
		Ogre::Entity* _Moneda14 = mSceneMgr->createEntity("Moneda14", "sphere.mesh");
		_Moneda14->setMaterial(coin);
		_nodeMoneda14->attachObject(_Moneda14);
		_nodeMoneda14->setScale(0.08,0.08,0.05);
		_nodeMoneda14->translate(0.77,7.517,5000.262);

		_nodeMoneda15 = mSceneMgr->createSceneNode("Moneda15");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda15);
		Ogre::Entity* _Moneda15 = mSceneMgr->createEntity("Moneda15", "sphere.mesh");
		_Moneda15->setMaterial(coin);
		_nodeMoneda15->attachObject(_Moneda15);
		_nodeMoneda15->setScale(0.08,0.08,0.05);
		_nodeMoneda15->translate(-70.77,7.517,5400.262);
		
	   _nodeMoneda16 = mSceneMgr->createSceneNode("Moneda16");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda16);
		Ogre::Entity* _Moneda16 = mSceneMgr->createEntity("Moneda16", "sphere.mesh");
		_Moneda16->setMaterial(coin);
		_nodeMoneda16->attachObject(_Moneda16);
		_nodeMoneda16->setScale(0.08,0.08,0.05);
		_nodeMoneda16->translate(50.77,7.517,5700.262);

		_nodeMoneda17 = mSceneMgr->createSceneNode("Moneda17");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda17);
		Ogre::Entity* _Moneda17 = mSceneMgr->createEntity("Moneda17", "sphere.mesh");
		_Moneda17->setMaterial(coin);
		_nodeMoneda17->attachObject(_Moneda17);
		_nodeMoneda17->setScale(0.08,0.08,0.05);
		_nodeMoneda17->translate(-50.77,7.517,6000.262);

		 _nodeMoneda18 = mSceneMgr->createSceneNode("Moneda18");
		mSceneMgr->getRootSceneNode()->addChild(_nodeMoneda18);
		Ogre::Entity* _Moneda18 = mSceneMgr->createEntity("Moneda18", "sphere.mesh");
		_Moneda18->setMaterial(coin);
		_nodeMoneda18->attachObject(_Moneda18);
		_nodeMoneda18->setScale(0.08,0.08,0.05);
		_nodeMoneda18->translate(60.77,7.517,6200.262);


		//Obstaculos
		_nodeObs1 = mSceneMgr->createSceneNode("Obs1");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs1);
		Ogre::Entity* _Obs1 = mSceneMgr->createEntity("Obs1", "Barrel.mesh");
		_nodeObs1->attachObject(_Obs1);
		_nodeObs1->setScale(6.0,6.0,6.0);
		_nodeObs1->translate(55.77,10.517,600.262);
		
		Ogre::SceneNode* _nodeObs2 = mSceneMgr->createSceneNode("Obs2");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs2);
		Ogre::Entity* _Obs2 = mSceneMgr->createEntity("Obs2", "Barrel.mesh");
		_nodeObs2->attachObject(_Obs2);
		_nodeObs2->setScale(6.0,6.0,6.0);
		_nodeObs2->translate(0.77,10.517,670.262);

		Ogre::SceneNode* _nodeObs3 = mSceneMgr->createSceneNode("Obs3");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs3);
		Ogre::Entity* _Obs3 = mSceneMgr->createEntity("Obs3", "Barrel.mesh");
		_nodeObs3->attachObject(_Obs3);
		_nodeObs3->setScale(6.0,6.0,6.0);
		_nodeObs3->translate(-50.77,10.517,800.262);

		Ogre::SceneNode* _nodeObs4 = mSceneMgr->createSceneNode("Obs4");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs4);
		Ogre::Entity* _Obs4 = mSceneMgr->createEntity("Obs4", "Barrel.mesh");
		_nodeObs4->attachObject(_Obs4);
		_nodeObs4->setScale(6.0,6.0,6.0);
		_nodeObs4->translate(100.77,10.517,1800.262);

		Ogre::SceneNode* _nodeObs5 = mSceneMgr->createSceneNode("Obs5");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs5);
		Ogre::Entity* _Obs5 = mSceneMgr->createEntity("Obs5", "Barrel.mesh");
		_nodeObs5->attachObject(_Obs5);
		_nodeObs5->setScale(6.0,6.0,6.0);
		_nodeObs5->translate(0.77,10.517,2000.262);

		Ogre::SceneNode* _nodeObs6 = mSceneMgr->createSceneNode("Obs6");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs6);
		Ogre::Entity* _Obs6 = mSceneMgr->createEntity("Obs6", "Barrel.mesh");
		_nodeObs6->attachObject(_Obs6);
		_nodeObs6->setScale(6.0,6.0,6.0);
		_nodeObs6->translate(-100.77,10.517,1800.262);

		
		Ogre::SceneNode* _nodeObs7 = mSceneMgr->createSceneNode("Obs7");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs7);
		Ogre::Entity* _Obs7 = mSceneMgr->createEntity("Obs7", "Barrel.mesh");
		_nodeObs7->attachObject(_Obs7);
		_nodeObs7->setScale(6.0,6.0,6.0);
		_nodeObs7->translate(-50.77,10.517,1500.262);

		Ogre::SceneNode* _nodeObs8 = mSceneMgr->createSceneNode("Obs8");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs8);
		Ogre::Entity* _Obs8 = mSceneMgr->createEntity("Obs8", "Barrel.mesh");
		_nodeObs8->attachObject(_Obs8);
		_nodeObs8->setScale(6.0,6.0,6.0);
		_nodeObs8->translate(-60.77,10.517,600.262);

		Ogre::SceneNode* _nodeObs9 = mSceneMgr->createSceneNode("Obs9");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs9);
		Ogre::Entity* _Obs9 = mSceneMgr->createEntity("Obs9", "Barrel.mesh");
		_nodeObs9->attachObject(_Obs9);
		_nodeObs9->setScale(6.0,6.0,6.0);
		_nodeObs9->translate(0.77,10.517,6400.262);

		Ogre::SceneNode* _nodeObs10 = mSceneMgr->createSceneNode("Obs10");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs10);
		Ogre::Entity* _Obs10 = mSceneMgr->createEntity("Obs10", "Barrel.mesh");
		_nodeObs10->attachObject(_Obs10);
		_nodeObs10->setScale(6.0,6.0,6.0);
		_nodeObs10->translate(100.77,10.517,6200.262);

		
		Ogre::SceneNode* _nodeObs11= mSceneMgr->createSceneNode("Obs11");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs11);
		Ogre::Entity* _Obs11 = mSceneMgr->createEntity("Obs11", "Barrel.mesh");
		_nodeObs11->attachObject(_Obs11);
		_nodeObs11->setScale(6.0,6.0,6.0);
		_nodeObs11->translate(-80.77,10.517,6000.262);

		Ogre::SceneNode* _nodeObs12 = mSceneMgr->createSceneNode("Obs12");
		mSceneMgr->getRootSceneNode()->addChild(_nodeObs12);
		Ogre::Entity* _Obs12 = mSceneMgr->createEntity("Obs12", "Barrel.mesh");
		_nodeObs12->attachObject(_Obs12);
		_nodeObs12->setScale(6.0,6.0,6.0);
		_nodeObs12->translate(0.77,10.517,5800.262);

		mSceneMgr->setSkyBox(true, "Examples/SpaceSkyBox", 300);
	}

};


int main (void)
{

	Example1 app;
	app.go();
	return 0;
}