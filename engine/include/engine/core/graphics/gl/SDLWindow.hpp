#pragma once

#include <engine/core/Core.hpp>

#include <engine/core/math/Vector2.hpp>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <engine/core/graphics/gl/Context.hpp>
#include <engine/core/graphics/IWindow.hpp>
#include <engine/core/graphics/gl/GLDebug.hpp>
#include <GL/glew.h>

#include <engine/core/events/Keys.hpp>

namespace phx
{
	namespace sdl
	{
		/**
		 * @brief Class to use SDL as a Windowing Library. See IWindow documentation for further information.
		 * 
		 */
		class SDLWindow : public phx::gfx::IWindow
		{
		public:
		  	/**
			 * @brief Creates the actual window
			 * 
			 * @param title 	Refer to IWindow documentation
			 * @param width 	Refer to IWindow documentation
			 * @param height 	Refer to IWindow documentation
			 * @param version 	Refer to IWindow documentation
			 * @param profile 	Refer to IWindow documentation
			 */
			SDLWindow(const std::string& title, int width, int height, phx::gfx::GLVersion version, phx::gfx::GLProfile profile);

			virtual void pollEvents();
			virtual void swapBuffers();
			virtual bool isRunning();
			virtual void close();

			virtual void setTitle(const char *title);
			virtual void getSize(int &width, int &height);
			virtual void setFullscreen(bool enabled);
			virtual void setResizable(bool enabled);
			virtual void setCursorState(phx::gfx::CursorState cursorState);
	
			virtual void setVSync(bool value);
			virtual void addKeyCallback(int eventType, int key, std::function<void()> callback);
			virtual void addMouseMoveCallback(std::function<void(double, double)> callback);
	
			inline SDL_Window* getSDLWindow() const { return m_window; }

		  	virtual bool isKeyDown(events::Keys key);
		 	virtual TVector2<int> getMousePosition();

		  	virtual void setMousePosition(TVector2<int> newPos);

		private:

			/// @brief The pointer to the window's data.
			SDL_Window* m_window;

			/// @brief The OpenGL context for the data.
			SDL_GLContext m_context;

			/// @brief Boolean to see if it is "still running".
			bool m_running;

			/// @brief Struct for storing KeyEvent callbacks and related data with it.
			struct KeyEvent_t {
				int eventType;
				int key;
				std::function<void()> callback;
			};

			/// @brief MouseMoveEvent callback "holder". Makes handling the data in the function definitions much easier.
			struct MouseMoveEvent_t {
				std::function<void(double,double)> callback;
			};

			/// @brief Vector for storing KeyEvents, is cycled through when a key event is recieved.
			std::vector<KeyEvent_t> m_keyEvents;

			/// @brief Vector for storing MouseMoveEvents, is cycled through when the mouse is moved.
			std::vector<MouseMoveEvent_t> m_mouseMoveEvents;
		};

	}
}
