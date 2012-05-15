/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "tbox.h"

/* ///////////////////////////////////////////////////////////////////////
 * aicb
 */
static tb_bool_t tb_aicb_work_func(tb_aicp_t* aicp, tb_aico_t const* aico, tb_aice_t const* aice)
{
	// check
	tb_assert_and_check_return_val(aicp && aico && aice, TB_FALSE);

	// ok
	return TB_TRUE;
}

/* ///////////////////////////////////////////////////////////////////////
 * main
 */
tb_int_t main(tb_int_t argc, tb_char_t** argv)
{
	// init
	if (!tb_init(malloc(1024 * 1024), 1024 * 1024)) return 0;

	// init
	tb_handle_t 	sock = TB_NULL;
	tb_handle_t 	aicp = TB_NULL;
	tb_handle_t 	aico = TB_NULL;

	// open sock
	sock = tb_socket_open(TB_SOCKET_TYPE_TCP);
	tb_assert_and_check_goto(sock, end);

	// init aicp
	aicp = tb_aicp_init(TB_AIOO_OTYPE_SOCK, 1);
	tb_assert_and_check_goto(aicp, end);

	// init aico
	aico = tb_aicp_addo(aicp, sock, tb_aicb_work_func, "work");
	tb_assert_and_check_goto(aico, end);

	// post conn
	tb_print("[demo]: conn: post");
	if (!tb_aicp_conn(aicp, aico, argv[1], tb_stou32(argv[2]))) goto end;

	// spak & done
	while (tb_aicp_spak(aicp) && tb_aicp_done(aicp)) ;
	
end:

	// close sock
	if (sock) tb_socket_close(sock);

	// exit aicp
	if (aicp) tb_aicp_exit(aicp);

	// exit
	tb_exit();
	return 0;
}