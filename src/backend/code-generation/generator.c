#include <math.h>
#include "../support/logger.h"
#include "generator.h"

/**
 * Implementación de "generator.h".
 */


//Macro para facilitar la modificacion de propiedades de un placeable
#define SET_PROPERTY(property_type, options_key, property_value) \
    case property_type: \
        options.options_key = list->property->value.property_value; \
        break;

#define IS_LINEAR_OBJECT(placeable_type) \
	(placeable_type == ARROW || placeable_type == SPRING || placeable_type == ROPE || placeable_type == SPACER)
#define IS_ALIGNMENT_OBJECT(placeable_type) \
	(placeable_type == ROW || placeable_type == COLUMN)

//Funcion principal que se encarga de llamar a la funciones de generacion de codigo para cada tipo de placeable 
//Esto lo realiza de manera recursiva, llamando la funcion para los hijos
object_t handle_placeable(Placeable* placeable, anchor_t anchor, canvas_t canvas, object_t parent);

//Estas fuciones de options devuelve el struct completado con las properties presentes y las que no estan presentes con sus defaults
block_opt get_block_options(PropertyList* list) {
	block_opt options = (block_opt) {
		.color = {255,255,255},
		.height = 100,
		.width = 100,
		.label = NULL
	};
	while(list != NULL){
		switch (list->property->key){
			SET_PROPERTY(COLOR_PROP, color, color)
			SET_PROPERTY(HEIGHT, height, number * 100)
			SET_PROPERTY(WIDTH, width, number * 100)
			SET_PROPERTY(LABEL, label, string)
		}
		list = list->next;
	}
	return options;
}

ball_opt get_ball_options(PropertyList* list) {
	ball_opt options = {
		.color = {255, 255, 255},
		.label = NULL,
		.radius = 50,
	};
	while(list!=NULL) {
		switch(list->property->key) {
			SET_PROPERTY(COLOR_PROP, color, color)
			SET_PROPERTY(LABEL, label, string)
			SET_PROPERTY(RADIUS, radius, number * 100)
		}
		list = list->next;
	}
	return options;
}

plane_opt get_plane_options(PropertyList* list){
	plane_opt options =  (plane_opt) {
		.color = {0, 0, 0},
		.label = NULL,
		.angle_label = NULL,
		.length = 500,
		.friction = false,
		.visible = true,
		.angle = 0.0
	};
	while(list != NULL){
		switch(list->property->key){
			SET_PROPERTY(COLOR_PROP, color, color)
			SET_PROPERTY(LABEL, label, string)
			SET_PROPERTY(ANGLE_LABEL, angle_label, string)
			SET_PROPERTY(LENGTH, length, number * 100)
			SET_PROPERTY(FRICTION, friction, boolean)
			SET_PROPERTY(VISIBLE, visible, boolean)
			SET_PROPERTY(ANGLE, angle, number)
		}
		list = list->next;
	}

	return options;
}

arrow_opt get_arrow_options(PropertyList* list) {
	arrow_opt options =  (arrow_opt) {
		.angle = 0,
		.angle_label = NULL,
		.color = {0,0,0},
		.direction = RIGHT,
		.double_arrow = false,
		.label = NULL,
		.reverse_arrow = false,
		.length = 100		
	};

	while(list!=NULL) {
		switch(list->property->key) {
			SET_PROPERTY(COLOR_PROP, color, color)
			SET_PROPERTY(LABEL, label, string)
			SET_PROPERTY(ANGLE, angle, number)
			SET_PROPERTY(ANGLE_LABEL, angle_label, string)
			SET_PROPERTY(DIRECTION, direction, direction)
			SET_PROPERTY(DOUBLE_ARROW, double_arrow, boolean)
			SET_PROPERTY(REVERSE_ARROW, reverse_arrow, boolean)
			SET_PROPERTY(LENGTH, length, number * 100)			
		}
		list = list->next;
	}
	return options;
}

rope_opt get_rope_options(PropertyList* list){
	rope_opt options =  (rope_opt){
		.color = {0,0,0},
		.label = NULL,
		.length = 100
	};
	while(list != NULL){
		switch(list->property->key){
			SET_PROPERTY(COLOR_PROP, color, color)
			SET_PROPERTY(LABEL, label, string)
			SET_PROPERTY(LENGTH, length, number * 100)
		}
		list = list->next;
	}
	return options;
}

spacer_opt get_spacer_options(PropertyList* list) {
	spacer_opt options =  (spacer_opt) {
		.length = 100
	};
	while(list != NULL){
		switch(list->property->key){
			SET_PROPERTY(LENGTH, length, number * 100)
		}
		list = list->next;
	}

	return options;
}

//Funcion principal, crea el ADT del SVG y empieza la llamada al handle_placeable desde la raiz del AST
//Luego libera todos los recursos usados y guarda el archivo SVG escrito
void generate_svg(){
	canvas_t canvas = create_canvas();
	Program* program = state.program; //Root del AST
	handle_placeable(state.program->placeable, state.program->placeable->position, canvas, (object_t) {
		.center = {0,0},
		.top = {0,0},
		.bottom = {0,0},
		.right = {0,0},
		.left = {0,0},
		.rotation = 0.0,
	});
	save_canvas(canvas);
	free_canvas(canvas);
}

void handle_column(canvas_t canvas, general_opt general_options, PlaceableList* list){
	//Esto sirve para rapidamente saber cuanto hay que rotar a la columna para dibujar desde cada anchor
	anchor_t draw_from_to_anchor[] = {BOTTOM, TOP, RIGHT_SIDE, LEFT_SIDE, CENTER, CENTER, CENTER};
	float rotation_needed_for_draw_from[] = {270.0f, 90.0f, 180.0f, 0.0f, 0.0f, 0.0f, 0.0f};

	anchor_t anchor = draw_from_to_anchor[general_options.draw_from];
	object_t last = {
		.center = general_options.starting_point,
		.top = general_options.starting_point,
		.bottom = general_options.starting_point,
		.right = general_options.starting_point,
		.left = general_options.starting_point,
		
		.rotation = general_options.rotation,
	};
	while(list!=NULL) {
		//Seteamos la rotacion en base a donde se puso la position
		last.rotation = general_options.rotation + ((IS_LINEAR_OBJECT(list->placeable->type)) ? rotation_needed_for_draw_from[general_options.draw_from] : 0.0f);
		last = handle_placeable(list->placeable, anchor, canvas, last);
		if(IS_LINEAR_OBJECT(list->placeable->type)) {//Si el que dibujo es un linear object hacemos que se dibuje desde la punta
			last = (object_t) {
				.center = last.end,
				.top = last.end,
				.bottom = last.end,
				.right = last.end,
				.left = last.end,
			};
		}
		last.rotation = general_options.rotation;
		list = list->next;
	}
		
}
//Funcion para como dice el nombre calcular el width de un object especifico para el manejo correcto de las filas
int calculate_width(Placeable *placeable) {
	PropertyList * propertyNode = placeable->properties;
	switch (placeable->type) {
		case ARROW:
			;
			arrow_opt arrow_options = get_arrow_options(propertyNode);
			return arrow_options.length *  cos(arrow_options.angle * M_PI/180);
		case ROPE:
			;
			rope_opt rope_options = get_rope_options(propertyNode);
			return rope_options.length;
		case SPRING:
			;
			rope_opt spring_options = get_rope_options(propertyNode);
			return spring_options.length;
		case SPACER:
			;
			spacer_opt spacer_options = get_spacer_options(propertyNode);
			return spacer_options.length;
		case HORIZONTAL_PLANE:
			;
			plane_opt plane_horizontal_options= get_plane_options(propertyNode);
			return plane_horizontal_options.length * cos(plane_horizontal_options.angle * M_PI/180);
		case VERTICAL_PLANE:
			;
			plane_opt plane_vertical_options = get_plane_options(propertyNode);
			return plane_vertical_options.length * sin(plane_vertical_options.angle * M_PI/180) + 1;
		case BLOCK:
		case CAR:
			;
			block_opt car_options = get_block_options(propertyNode);
			return car_options.width;
		case BALL:
			;
			ball_opt ball_options = get_ball_options(propertyNode);
			return ball_options.radius * 2;
	}
}


void handle_row(canvas_t canvas, general_opt general_options, PlaceableList* list) {
	float rotation_needed_for_draw_from[] = {-180.0f, 0.0f, -90.0f, 90.0f, 0.0f, 0.0f, 0.0f};	PlaceableList *start_list = list;
	anchor_t anchor = TOP;
	int total_width = 0;
	
	int first_children_width = 0;

	while (start_list != NULL) {
		int child_width = calculate_width(start_list->placeable);
		total_width += child_width;
		if (first_children_width == 0) first_children_width += child_width;
		start_list = start_list->next;
	}

	total_width -= first_children_width;

	general_options.rotation = rotation_needed_for_draw_from[general_options.draw_from] + general_options.rotation;

	point_t starting_point = general_options.starting_point;

	float total_rotation = (general_options.rotation) * M_PI/180;

	general_options.starting_point = (point_t) {
		.x = general_options.starting_point.x - total_width / 2 * cos(total_rotation),
		.y = general_options.starting_point.y + total_width / 2 * sin(total_rotation),
	};


	object_t last = {
		.center = general_options.starting_point,
		.top = general_options.starting_point,
		.bottom = general_options.starting_point,
		.right = general_options.starting_point,
		.left = general_options.starting_point,
		.rotation = general_options.rotation,
	};

	while (list != NULL) {
		last = handle_placeable(
			list->placeable, 
			anchor, 
			canvas, 
			last
		);
		if(IS_LINEAR_OBJECT(list->placeable->type)) {
			last = (object_t) {
				.center = last.end,
				.top = last.end,
				.bottom = last.end,
				.right = last.end,
				.left = last.end,
			};
		}
		anchor = RIGHT_SIDE;
		last.rotation = general_options.rotation;

		list = list->next;
	}
}


object_t handle_placeable(Placeable* placeable, anchor_t anchor, canvas_t canvas, object_t parent){
	
	general_opt general_options = {
		.rotation = parent.rotation
	};
	//Seteamos las opciones con las que se dibujaran en base al padre
	switch(anchor) {
		case TOP:
			general_options.draw_from = f_BOTTOM;
			general_options.starting_point = parent.top;
			break;
		case BOTTOM:
			general_options.draw_from = f_TOP;
			general_options.starting_point = parent.bottom;
			break;
		case LEFT_SIDE:
			general_options.draw_from = f_RIGHT;
			general_options.starting_point = parent.left;
			break;
		case RIGHT_SIDE:
			general_options.draw_from = f_LEFT;
			general_options.starting_point = parent.right;
			break;
		case CENTER:
		case NO_ANCHOR:
			general_options.draw_from = f_CENTER;
			general_options.starting_point = parent.center;
			break;
		default:
			break;
	}
	if(IS_LINEAR_OBJECT(placeable->type)){
		general_options.draw_from = f_START;
	}
	PropertyList * propertyNode = placeable->properties;
	object_t object;
	//Revisamos el tipo, obtenemos las properties y llamamos a la funcion correspondiente de draw.c
	switch(placeable->type){
		case ROW:
			handle_row(canvas, general_options, placeable->composedPlaceables);
		    return object;
			
			break;
		case COLUMN:
			handle_column(canvas, general_options, placeable->composedPlaceables);
			return object;
			
			break;
		case ARROW:
			;
			arrow_opt arrow_options = get_arrow_options(propertyNode);
			object = draw_arrow(canvas, general_options, arrow_options);
			break;
		case ROPE:
			;
			rope_opt rope_options = get_rope_options(propertyNode);
			object = draw_rope(canvas, general_options, rope_options);
			break;
		case SPRING:
			;
			rope_opt spring_options = get_rope_options(propertyNode);
			object = draw_spring(canvas, general_options, spring_options);
			break;
		case SPACER:
			;
			spacer_opt spacer_options = get_spacer_options(propertyNode);
			object = draw_spacer(canvas, general_options, spacer_options);	
			break;
		case HORIZONTAL_PLANE:
			;
			plane_opt plane_horizontal_options= get_plane_options(propertyNode);
			object = draw_horizontal_plane(canvas,general_options, plane_horizontal_options);
			break;
		case VERTICAL_PLANE:
			;
			plane_opt plane_vertical_options= get_plane_options(propertyNode);
			object = draw_vertical_plane(canvas,general_options, plane_vertical_options);
			break;
		case BLOCK:
			;
			block_opt block_options = get_block_options(propertyNode);
			object = draw_block(canvas, general_options, block_options);
			break;
		case CAR:
			;
			block_opt car_options = get_block_options(propertyNode);
			object = draw_car(canvas, general_options, car_options);
			break;
		case BALL:
			;
			ball_opt ball_options = get_ball_options(propertyNode);
			object = draw_ball(canvas, general_options, ball_options);
			break;
	}

	PlaceableList* children = placeable->composedPlaceables;
	//Iteramos a los hijos y llamamos de manera recursiva a la funcion
	while(children!=NULL) {
		handle_placeable(children->placeable, children->placeable->position, canvas, object);
		children = children->next;
	}
	return object;
}




