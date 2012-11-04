#include "SCML_cocos2dx.h"
#include <vector>
#include <list>

using namespace std;
using namespace cocos2d;
using namespace SCML_cocos2dx;




class Test : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(Test);

	bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
};


CCScene* Test::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        Test *layer = Test::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Test::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

		/*Entity *animator = Entity::create("Example.SCML");

		CC_BREAK_IF(! animator);

		animator->setPosition(ccp(400, 300));
		//animator->setScale(0.8f);
		
		this->addChild(animator, 0, 100);*/


		CCDirector* pDirector = CCDirector::sharedDirector();
		pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

        bRet = true;

    } while (0);

    return bRet;
}

void Test::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}


bool Test::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	/*Entity *animator = (Entity *)this->getChildByTag(100);

	if (animator)
		animator->PlayNext();*/

    return true;
}




class  AppDelegate : private cocos2d::CCApplication
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual bool applicationDidFinishLaunching();

    virtual void applicationDidEnterBackground();

    virtual void applicationWillEnterForeground();
};

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
    //pDirector->enableRetinaDisplay(true);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = Test::scene();

    // run
    pDirector->runWithScene(pScene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
}




void main_loop(vector<string>& data_files)
{
    CCApplication::sharedApplication()->run();
}




bool init(unsigned int w, unsigned int h)
{
    
    AppDelegate app;
    //CCApplication::sharedApplication()->setResourceRootPath(".");
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setFrameSize(800, 600);
    
    return true;
}

void quit()
{
    
}

