#include <fstream>
#include <string>
#include <vector>
#include "Shader.h"

Shader::Shader() {
	// Create the shaders
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Create the program (this doesn't work when created here...?)
	// program = glCreateProgram();
}

Shader::Shader(const char *vertex_file_path, const char *fragment_file_path) {
	// Create the shaders
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	create(vertex_file_path, fragment_file_path);
}

Shader::~Shader() {
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

GLuint Shader::getProgram() {
	return program;
}

void Shader::registerUniform(const char *name) {
	GLuint id = glGetUniformLocation(program, name);
	uniforms.insert(std::pair<const char*, GLuint>(name, id));
}

GLuint Shader::getUniform(const char *name) {
	// This should throw an exception when `name` is not in `uniforms`
	return uniforms[name];
	// return uniforms.at(name);
}

// Read the shader code from the file
void Shader::loadFromSource(GLuint shader, const char *file_path) {
	std::string shaderCode;
	std::ifstream shaderStream(file_path, std::ios::in);
	if (shaderStream.is_open()) {
		std::string line = "";
		while(getline(shaderStream, line))
			shaderCode += "\n" + line;
		shaderStream.close();
	}

	GLint result = GL_FALSE;

	// Compile Shader
	fprintf(stdout, "Compiling shader: \"%s\"...", file_path);
	char const * sourcePointer = shaderCode.c_str();
	glShaderSource(shader, 1, &sourcePointer , NULL);
	glCompileShader(shader);

	// Check Shader
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (!result) {
		std::vector<char> infoLog(512);
		glGetShaderInfoLog(shader, infoLog.size(), NULL, &infoLog[0]);
		fprintf(stdout, "\n%s\n", &infoLog[0]);
	} else {
		fprintf(stdout, "success\n");
	}
}

void Shader::create(const char *vertex_file_path, const char *fragment_file_path)
{
	loadFromSource(vertexShader, vertex_file_path);
	loadFromSource(fragmentShader, fragment_file_path);

	// Link the program
	fprintf(stdout, "Linking program...");
	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	GLint result = GL_FALSE;

	// Check the program
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	if (!result) {
		std::vector<char> infoLog(512);
		glGetProgramInfoLog(program, infoLog.size(), NULL, &infoLog[0]);
		fprintf(stdout, "\n%s\n", &infoLog[0]);
	} else {
		fprintf(stdout, "success\n");
	}

	// glDeleteShader(vertexShader);
	// glDeleteShader(fragmentShader);
}

void Shader::setCurrent() {
	glUseProgram(program);
}

void Shader::setUniform1i(const char *name, const GLuint value) {
	// GLuint handle = glGetUniformLocation(program, name);
	GLuint handle = getUniform(name);
	glUniform1i(handle, value);
}

void Shader::setUniform1f(const char *name, const GLfloat value) {
	// GLuint handle = glGetUniformLocation(program, name);
	GLuint handle = getUniform(name);
	glUniform1f(handle, value);
}

void Shader::setUniform2fv(const char *name, const GLfloat *value) {
	// GLuint handle = glGetUniformLocation(program, name);
	GLuint handle = getUniform(name);
	glUniform2fv(handle, 2, &value[0]);
}

void Shader::setUniform3fv(const char *name, const GLfloat *value) {
	// GLuint handle = glGetUniformLocation(program, name);
	GLuint handle = getUniform(name);
	glUniform3fv(handle, 3, &value[0]);
}

void Shader::setUniform4fv(const char *name, const GLfloat *value) {
	// GLuint handle = glGetUniformLocation(program, name);
	GLuint handle = getUniform(name);
	glUniform4fv(handle, 4, &value[0]);
}

void Shader::setUniformMatrix4fv(const char *name, const GLfloat *value) {
	// GLuint handle = glGetUniformLocation(program, name);
	GLuint handle = getUniform(name);
	glUniformMatrix4fv(handle, 1, GL_FALSE, value);
}
