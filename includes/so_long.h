/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:32:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/25 01:02:00 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "../utils/libft/libft.h"
# include <stdlib.h>
# include "../utils/get_next_line/get_next_line.h"

# define VICTOR "images/victor.xpm"
# define WALLS "images/wall.xpm"
# define BRAHMA "images/brahma.xpm"
# define FLOOR "images/floor.xpm"
# define EXIT "images/exit.xpm"
# define W_PLAYER "images/w.xpm"
# define A_PLAYER "images/a.xpm"
# define S_PLAYER "images/victor.xpm"
# define D_PLAYER "images/d.xpm"

# define SPRITE 64

enum	e_keys

{
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	ESC = 53
};

// My struct for player in my game:

typedef struct	s_avatar

{
	int		pos_w;
	int		pos_h;
}	t_avatar;

// My struct's struct for my game:

typedef struct	s_config


{
	void	*server;
	void	*win;
	void	*player;
	void	*floor;
	void	*walls;
	void	*brahma;
	void	*exit;


	int		end;
	int		avatar_move;
	int		phase_columns;
	int		phase_rows;
	
	int		count_brahmas;
	
	int		coin_amount;
	int		avatar_amount;
	int		exit_amount;
	int		wall_amount;

	char		**phase;
	char		**cp_map;
	char		**map;

	t_avatar	avatar;

}	t_config;

int		possible_move(int wid, int hei, t_config *config);
void    avatar_img(t_config *config, char *sprite);
void    avatar_move(t_config *config, int wid, int hei);
void    moviments(int keycode, t_config *config);
int		keys_game(int keycode, t_config *config);
int 	start_game(t_config *config);
void    *input_image(t_config *config, char *path_img);
void    insert(t_config *config, void *image, int wid, int hei);
void    set_phase(t_config *config, int wid, int hei);
int		append_map(t_config *config);
void    append_map_size(t_config *config);
char    **reader(int fd);
char    **map_generator(t_config *config, char *path_file);
int		close_window(int keycode, t_config *config);
void	start_variables(t_config *config);
int		error_msg(char *msg);
int		ft_valid(t_config *config);
int		has_plus_newline(char *string);
int		valid_path(t_config *config, int i, int j);
int		exit_tester(t_config *cp, int i, int j);
int		game_finish(t_config *config);
void	free_to_maps(char **map);
int		validator(t_config *config);
void	avatar_steps(t_config *config); 


#endif
