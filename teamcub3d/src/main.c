/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:08:44 by yongmipa          #+#    #+#             */
/*   Updated: 2023/05/24 17:35:36 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// void	leak(void)
// {
// 	system("leaks cub3D");
// }

int	main(int ac, char *av[])
{
	t_game	*game;
	int		fd;

	// atexit(leak);
	if (ac != 2)
		ft_err("invalid argument count", 0);
	if (!check_extension(av[1], ".cub"))
		ft_err("invalid file argument extention", 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_err("Failed to open file", 0);
	game = init_game();
	if (!validate_all(read_file(fd, game), game))
		ft_err("map error!", game);
	close(fd);
	game->window = mlx_new_window(game->mlx, W, H, "cub3D");
	// hi_cute_3d(game);
	// mlx_hook(game->window, KEY_PRESS, 0, press_key, game);
	// mlx_hook(game->window, DESTROY_NOTIFY, 0, exit_game, game);
	ray_main(game); // 이거 주석되어있어서 그럴듯요!!!
	// mlx_loop_hook(game->mlx, main_loop, game);
	// // mlx_hook(game->window, 17, 0, main_loop, game);
	// mlx_hook(game->window, 17, 0, press_key, game);
	// mlx_loop(game->mlx);
	return (0);
}

/*
제 생각 수순 및 주의 할 점

1. 인자 체크
	1-1. ac == 2 랑 3만 됨
		2-1. 2 일 경우 = 맵들어온 경우
		2-2. 3 일 경우 = --save 들어옴
2. 지도 파일 체크
	2-1. .cub 로 끝나는 지 확인
	2-2. 4개의 문자로만 구성되는지 (0, 1, 2, [N, S, E, W]중 하나)
	2-3. 벽으로 둘러 쌓여 있는지
	2-4. 지도 내용은 항상 맨 마지막에 있어야 함 [ 맵에 대한 정보(해상도, 벽 텍스쳐들, 색상들 등등) 이후에 지도가 나와야함]
	2-5. 지도 내용안에서 공백은 있으면 x (벽과 벽 사이는 가능)
	2-6. 멥에 대한 정보들은 '하나 이상의' 공백으로 구분 될 수 있음
	2-7. 맵에 대한 정보들의 값이 유효한지
3. 초기값 세팅 & 이미지 파일 연결 
4. 게임 시작
	4-1. 캐릭터 이동 시 레이케스팅
	4-2. esc 종료, x 표시 종료
	4-3. 


*/


/*

1. validation
-	인자, 맵
	-맵 유효성 검사 목록
		1. 맵에 표현해야 할 구성 요소 외에 다른 요소가 존재?.
		2. 맵은 반드시 벽으로 둘러싸여 있어야한다.
		3. 맵 구성 요소는 개행으로 구분될 수 있다.
		4. 인자 순서에서 맵은 가장 마지막에 와야한다. (나머지 요소 순서는 알빠래여)
		5. 맵 제외 다른 요소들은 하나 혹은 더 많은 수의 스페이스바로 구분할 수 있다.
		6. 맵은 유효성을 지닌다면, 어떤 형식이든 파싱이 되어야만한다.
		7. 맵 제외 다른 요소들은 type identifier에 엄격히 따른다.
		8. 파일, 맵에서 validation에 실패했다면, 올바르게 exit후 상황을 담은 적절한 에러메세지가 필요하다.

		3D로 시야를 그린다는건.......................레이캐스팅을 해야한대여
		https://github.com/365kim/raycasting_tutorial
		https://github.com/terry-yes/mlx_example
		// mlx랑 친해져여~

		
		유효성 검사 -> 맵 파싱 -> 레이캐스팅 공부 여기부터 해야될거같은데... 버억

	맵 파싱?
	이번 과제의 맵은 직사각형이 아니다.
	한줄 씩 검수를 하는게 먼저 떠오르는뎅... 더 좋은 방식 있으면 추천받습니다.
	
	1. 무죅건 벽으로 둘러싸여 있어야 한다.
	2. 방향키는 카메라 무빙(좌우만 있네여?), WASD는 캐릭터 움직이기
	3. 확장자는 .cub
	4. 맵의 구성요소는 0, 1, NSEW(캐릭터 시작위치 겸 방향)
*/