#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <map>

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif

class Shader {
public:
	Shader();
	Shader(const char *vertex_file_path, const char *fragment_file_path);
	~Shader();
	GLuint getProgram();
	void create(const char *vertex_file_path, const char *fragment_file_path);
	void registerUniform(const char *name);
	GLuint getUniform(const char *name);
	void setCurrent();
	void setUniform1i(const char *name, const GLuint value);
	void setUniform1f(const char *name, const GLfloat value);
	void setUniform2fv(const char *name, const GLfloat *value);
	void setUniform3fv(const char *name, const GLfloat *value);
	void setUniform4fv(const char *name, const GLfloat *value);
	void setUniformMatrix4fv(const char *name, const GLfloat *value);
private:
	GLuint vertexShader, fragmentShader, program;
	std::map<std::string, GLuint> uniforms;
	void loadFromSource(GLuint shader, const char *file_path);
};

#endif
