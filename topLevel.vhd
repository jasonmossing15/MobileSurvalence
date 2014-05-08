----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:51:18 04/22/2014 
-- Design Name: 
-- Module Name:    topLevel - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity topLevel is
    Port ( clk : in  STD_LOGIC;
			  reset : in std_logic;
           buttonR : in  STD_LOGIC;
			  buttonL : in  STD_LOGIC;
           btnL : out  STD_LOGIC;
			  btnR : out  STD_LOGIC;
			  buttonU : in  STD_LOGIC;
			  buttonD : in  STD_LOGIC;
           btnU : out  STD_LOGIC;
			  btnD : out  STD_LOGIC);
end topLevel;


architecture Behavioral of topLevel is

signal count_clk, out_s : std_logic;
signal rightPress, rightPulse : std_logic;
signal leftPress, leftPulse : std_logic;
signal output : std_logic_vector(7 downto 0);


begin


	 inst_rightPush : entity work.input_to_pulse_with_held
		    Port map ( 
					clk => clk,
					reset => reset,
					input => buttonR,
					hold => btnR,
					pulse => open
					);

		 inst_leftPush : entity work.input_to_pulse_with_held
		    Port map ( 
					clk => clk,
					reset => reset,
					input => buttonL,
					hold => btnL,
					pulse => open
					);

			inst_upPush : entity work.input_to_pulse_with_held
		    Port map ( 
					clk => clk,
					reset => reset,
					input => buttonU,
					hold => btnU,
					pulse => open
					);

		 inst_downPush : entity work.input_to_pulse_with_held
		    Port map ( 
					clk => clk,
					reset => reset,
					input => buttonD,
					hold => btnD,
					pulse => open
					);


end Behavioral;

