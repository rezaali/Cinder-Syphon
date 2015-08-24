#pragma once 

#include "cinder/gl/gl.h"

namespace reza { namespace syphon {
    
typedef std::shared_ptr<class Server> ServerRef;
class Server
{
public:
    static ServerRef create()
    {
        return ServerRef( new Server() );
    }
    
    ~Server();
    
	void setName( const std::string& name );
	std::string getName();

    void publishScreen();
    void publishTexture( ci::gl::TextureRef texture );
    
    void bind( glm::vec2 size );
    void unbind();
    
protected:
    Server();

    ci::gl::Texture2dRef mTexture;
    bool mBinded;
	void *mServer;
};

} } // namespace reza::syphon